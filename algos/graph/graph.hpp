#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <forward_list>
#include <unordered_set>
#include "../../structs/graphs/adjacency_list/graph_adj_list.hpp"
#include "../../structs/graphs/adjacency_matrix/graph_adj_mat.hpp"

namespace cra {

// Breadth-First Search ---------------------------------------------------------- O(V+E)
template <class WeightType>
void bfs(const crs::GraphAdjList<WeightType>& G, size_t src,
        std::unordered_map<size_t, WeightType>& distance,
        std::unordered_map<size_t, size_t>& predecessor);

template <bool Directed, class WeightType>
void bfs(const crs::GraphAdjMat<Directed, WeightType>& G, size_t src,
         std::vector<WeightType>& distance, std::vector<size_t>& predecessor);

// Depth-First Search ------------------------------------------------------------ O(V+E)
template <class WeightType>
void dfs(const crs::GraphAdjList<WeightType>& G,
         std::unordered_map<size_t, size_t>& predecessor,
         std::unordered_map<size_t, std::pair<size_t, size_t>>& time);

template <class WeightType>
static void dfs_rec(const crs::GraphAdjList<WeightType>& G, 
                    size_t vertex, size_t& curr_t,
                    std::unordered_set<size_t>& visited,
                    std::unordered_map<size_t, size_t>& predecessor,
                    std::unordered_map<size_t, std::pair<size_t, size_t>>& time);

template <class WeightType>
void dfs_stk(const crs::GraphAdjList<WeightType>& G,
         std::unordered_map<size_t, size_t>& predecessor,
         std::unordered_map<size_t, std::pair<size_t, size_t>>& time);

template <bool Directed, class WeightType>
void dfs(const crs::GraphAdjMat<Directed, WeightType>& G,
         std::vector<size_t>& predecessor,
         std::vector<std::pair<size_t, size_t>>& time);

template <bool Directed, class WeightType>
static void dfs_rec(const crs::GraphAdjMat<Directed, WeightType>& G,
                    size_t vertex, size_t& curr_t,
                    std::vector<bool>& visited,
                    std::vector<size_t>& predecessor,
                    std::vector<std::pair<size_t, size_t>>& time);

// Cycle Detection
        // directed vs undirected

// Topological Sort -------------------------------------------------------------- O(V+E)
template <class WeightType>
void topo_sort(const crs::GraphAdjList<WeightType>& G,
               std::vector<size_t>& list);

template <class WeightType>
void topo_sort_rec(const crs::GraphAdjList<WeightType>& G,
                   std::forward_list<size_t>& list,
                   std::unordered_set<size_t>& visited,
                   size_t vertex);

        // Kahn

// Strongly Connected Components

// Kruskal

// Prim

// Bellman-Ford

// Dijkstra

// A*

// Floyd-Warshall

// Johnson

}   // cra namespace (c. roman algorithms [library])

#include "graph.tpp"

#endif  // GRAPH_HPP