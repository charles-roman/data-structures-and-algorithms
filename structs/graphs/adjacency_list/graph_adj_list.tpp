#include <iostream>
#include <algorithm>
#include "graph_adj_list.hpp"

namespace crs {

template <class WeightType>
GraphAdjList<WeightType>::GraphAdjList() : edges_(0), adj({}) {}

template <class WeightType>
bool GraphAdjList<WeightType>::add_vertex(size_t v) {
    if (has_vertex(v)) return false;

    adj[v] = {};
    return true;
}

template <class WeightType>
bool GraphAdjList<WeightType>::add_edge(size_t u, size_t v, bool dir, WeightType weight) {
    if (!has_vertex(u) || !has_vertex(v)) return false;

    Edge e(v, dir, weight);
    adj[u].push_back(e);
    if (!dir) {
        Edge r(u, dir, weight);
        adj[v].push_back(r);
    }
    ++edges_;
    return true;
}

template <class WeightType>
bool GraphAdjList<WeightType>::remove_vertex(size_t v) {
    if (!has_vertex(v)) return false;

    size_t count_dir = 0, count_undir = 0;
    for (auto& [u, list] : adj) {
        auto it = list.begin();
        while (it != list.end()) {
            if (it->dest_ == v || u == v) {
                auto temp = it;
                ++it;
                if (temp->dir_) {
                    ++count_dir;
                } else {
                    ++count_undir;
                }
                list.erase(temp);
            } else {
                ++it;
            }
        }
    }
    adj.erase(v);
    edges_ -= (count_dir + count_undir / 2);
    return true;
}

template <class WeightType>
size_t GraphAdjList<WeightType>::remove_edge(size_t u, size_t v, bool dir, WeightType weight) {
    size_t count = adj[u].remove(Edge(v, dir, weight));
    if (!dir && count > 0) {
        adj[v].remove(Edge(u, dir, weight));
    }
    edges_ -= count;
    return count;
}

template <class WeightType>
bool GraphAdjList<WeightType>::has_vertex(size_t v) const {
    return adj.contains(v);
}

template <class WeightType>
size_t GraphAdjList<WeightType>::has_edge(size_t u, size_t v, bool dir, WeightType weight) const {
    if (!has_vertex(u) || !has_vertex(v)) return false;

    return std::count(adj[u].begin(), adj[u].end(), Edge(v, dir, weight));
}

template <class WeightType>
std::vector<size_t> GraphAdjList<WeightType>::vertices() const {
    std::vector<size_t> vertices;
    for (const auto& [v, list] : adj) {
        vertices.push_back(v);
    }
    return vertices;
}

template <class WeightType>
std::vector<size_t> GraphAdjList<WeightType>::adj_vertices(size_t v) const {
    std::vector<size_t> vertices;
    if (has_vertex(v)) {
        auto it = adj.find(v);
        for (const auto& e : it->second) {
            vertices.push_back(e.dest_);
        }
    }
    return vertices;
}

template <class WeightType>
std::pair<size_t, size_t> GraphAdjList<WeightType>::size() const {
    return {adj.size(), edges_};
}

template <class WeightType>
void GraphAdjList<WeightType>::clear() {
    adj.clear();
}

template <class WeightType>
void GraphAdjList<WeightType>::print() const {
    for (const auto& [v, list] : adj) {
        std::cout << "(vertex " << v << ") -> ";
        for (const auto& e : list) {
            std::cout << "(vertex: " << e.dest_ << ", weight: " << e.weight_ << ") ";
        }
        std::cout << std::endl;
    }
}

}   // namespace crs (c. roman [data] structures [library])