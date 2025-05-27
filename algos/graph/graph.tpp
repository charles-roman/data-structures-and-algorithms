#include <queue>
#include <stack>
#include "graph.hpp"

namespace cra {

// --------------------------------------------------------------------------- Breadth-First Search
template <class WeightType>
void bfs(const crs::GraphAdjList<WeightType>& G, size_t src,
         std::unordered_map<size_t, WeightType>& distance,
         std::unordered_map<size_t, size_t>& predecessor) {

    std::unordered_map<size_t, bool> visited;
    visited[src] = true;
    distance[src] = 0;
    predecessor[src] = SIZE_MAX;

    std::queue<size_t> q;
    q.push(src);

    while (!q.empty()) {
        size_t u = q.front();
        q.pop();
        for (const size_t v : G.adj_vertices(u)) {
            if (!visited.contains(v)) {
                distance[v] = distance[u] + 1;
                predecessor[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

template <bool Directed, class WeightType>
void bfs(const crs::GraphAdjMat<Directed, WeightType>& G, size_t src,
         std::vector<WeightType>& distance, std::vector<size_t>& predecessor) {
    
    auto [V, E] = G.size();
    std::vector<bool> visited(V, false);
    visited[src] = true;

    distance.assign(V, std::numeric_limits<WeightType>::max());
    distance[src] = 0;

    predecessor.assign(V, SIZE_MAX);
    predecessor[src] = SIZE_MAX;

    std::queue<size_t> q;
    q.push(src);

    while (!q.empty()) {
        size_t u = q.front();
        q.pop();
        for (size_t v = 0; v < V; ++v) {
            if (G.has_edge(u, v) && !visited[v]) {
                distance[v] = distance[u] + 1;
                predecessor[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// --------------------------------------------------------------------------- Depth-First Search
template <class WeightType>
void dfs(const crs::GraphAdjList<WeightType>& G, 
         std::unordered_map<size_t, size_t>& predecessor,
         std::unordered_map<size_t, std::pair<size_t, size_t>>& time) {

    std::unordered_set<size_t> visited;
    size_t curr_t = 0;

    for (const size_t v : G.vertices()) {
        if (!visited.contains(v)) {
            predecessor[v] = SIZE_MAX;
            dfs_rec(G, v, curr_t, visited, predecessor, time);
        }
    }
}

template <class WeightType>
static void dfs_rec(const crs::GraphAdjList<WeightType>& G,
                    size_t vertex, size_t& curr_t,
                    std::unordered_set<size_t>& visited,
                    std::unordered_map<size_t, size_t>& predecessor,
                    std::unordered_map<size_t, std::pair<size_t, size_t>>& time) {

    ++curr_t;
    time[vertex].first = curr_t;
    visited.insert(vertex);
    for (const size_t v : G.adj_vertices(vertex)) {
        if (!visited.contains(v)) {
            predecessor[v] = vertex;
            dfs_rec(G, v, curr_t, visited, predecessor, time);
        }
    }
    ++curr_t;
    time[vertex].second = curr_t;
}

template <class WeightType>
void dfs_stk(const crs::GraphAdjList<WeightType>& G,
         std::unordered_map<size_t, size_t>& predecessor,
         std::unordered_map<size_t, std::pair<size_t, size_t>>& time) {
    
    std::unordered_set<size_t> visited;
    std::stack<size_t> stk;
    std::stack<size_t> stk2;    // could also use a stack with pairs
    size_t curr_t = 0;

    for (const size_t u : G.vertices()) {
        if (visited.contains(u)) continue;

        size_t i = 0;
        ++curr_t;
        time[u].first = curr_t;
        predecessor[u] = SIZE_MAX;
        visited.insert(u);
        stk.push(u);
        stk2.push(i);

        while (!stk.empty()) {
            size_t v = stk.top();
            if (i < G.adj_vertices(v).size()) {
                v = G.adj_vertices(v).at(i);
                if (!visited.contains(v)) {
                    ++curr_t;
                    time[v].first = curr_t;
                    predecessor[v] = stk.top();
                    visited.insert(v);
                    stk.push(v);
                    stk2.push(i);
                    i = 0;
                } else {
                    ++i;
                }
            } else {
                ++curr_t;
                time[v].second = curr_t;
                stk.pop();
                i = stk2.top();
                stk2.pop();
            }
        }
    }
}

template <bool Directed, class WeightType>
void dfs(const crs::GraphAdjMat<Directed, WeightType>& G,
         std::vector<size_t>& predecessor,
         std::vector<std::pair<size_t, size_t>>& time) {

    const auto [V, E] = G.size();
    std::vector<bool> visited(V, false);
    predecessor.assign(V, SIZE_MAX);
    time.assign(V, {0, 0});
    size_t curr_t = 0;

    for (size_t u = 0; u < V; ++u) {
        if (!visited[u]) {
            predecessor[u] = SIZE_MAX;
            dfs_rec(G, u, curr_t, visited, predecessor, time);
        }
    }
}

template <bool Directed, class WeightType>
static void dfs_rec(const crs::GraphAdjMat<Directed, WeightType>& G,
                    size_t vertex, size_t& curr_t,
                    std::vector<bool>& visited,
                    std::vector<size_t>& predecessor,
                    std::vector<std::pair<size_t, size_t>>& time) {

    time[vertex].first = ++curr_t;
    visited[vertex] = true;
    for (const size_t v : G.adj_vertices(vertex)) {
        if (!visited[v]) {
            predecessor[v] = vertex;
            dfs_rec(G, v, curr_t, visited, predecessor, time);
        }
    }
    time[vertex].second = ++curr_t;
}

// --------------------------------------------------------------------------- Topological Sort
template <class WeightType>
void topo_sort(const crs::GraphAdjList<WeightType>& G,
               std::forward_list<size_t>& list) {

    // optional: check for cycle
    list.clear();
    std::unordered_set<size_t> visited;

    for (const size_t u : G.vertices()) {
        if (!visited.contains(u)) {
            topo_sort_rec(G, list, visited, u);
        }
    }
}

template <class WeightType>
void topo_sort_rec(const crs::GraphAdjList<WeightType>& G,
                   std::forward_list<size_t>& list,
                   std::unordered_set<size_t>& visited,
                   size_t vertex) {
    
    visited.insert(vertex);
    for (const size_t v : G.adj_vertices(vertex)) {
        if (!visited.contains(v)) {
            topo_sort_rec(G, list, visited, v);
        }
    }
    list.push_front(vertex);
}

}   // cra namespace (c. roman algorithms [library])