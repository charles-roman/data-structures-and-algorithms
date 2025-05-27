#include <iostream>
#include <limits>
#include "graph_adj_mat.hpp"

namespace crs {

template <bool Directed, class WeightType>
GraphAdjMat<Directed, WeightType>::GraphAdjMat() 
    : WEIGHT_MAX(std::numeric_limits<WeightType>::max()), edges_(0), adj({}) {}

template <bool Directed, class WeightType>
GraphAdjMat<Directed, WeightType>::GraphAdjMat(size_t vertices) 
    : WEIGHT_MAX(std::numeric_limits<WeightType>::max()), edges_(0),
        adj(std::vector<std::vector<WeightType>>(vertices, std::vector<WeightType>(vertices, WEIGHT_MAX))) {}

template <bool Directed, class WeightType>
void GraphAdjMat<Directed, WeightType>::add_vertex() {
    for (auto& row : adj) {
        row.push_back(WEIGHT_MAX);
    }
    adj.push_back(std::vector<WeightType>(adj.empty() ? 1 : adj[0].size(), WEIGHT_MAX));
}

template <bool Directed, class WeightType>
bool GraphAdjMat<Directed, WeightType>::add_edge(size_t u, size_t v, WeightType weight) {
    if (!has_vertex(u) || !has_vertex(v) || has_edge(u, v) || has_edge(v, u)) return false;

    adj[u][v] = weight;
    if constexpr (!Directed) {
        adj[v][u] = weight;
    }
    ++edges_;
    return true;
}

template <bool Directed, class WeightType>
bool GraphAdjMat<Directed, WeightType>::remove_vertex(size_t v) {
    if (!has_vertex(v)) return false;

    size_t count = 0;
    for (auto& row : adj) {
        auto it = row.begin() + v;
        if (*it != WEIGHT_MAX) ++count;
        row.erase(it);
    }

    for (auto& w : adj[v]) {
        if (w != WEIGHT_MAX) ++count;
    }
    adj.erase(adj.begin() + v);

    if constexpr (Directed) {
        edges_ -= count;
    } else {
        edges_ -= (count / 2);
    }
    
    return true;
}

template <bool Directed, class WeightType>
bool GraphAdjMat<Directed, WeightType>::remove_edge(size_t u, size_t v) {
    if (!has_vertex(u) || !has_vertex(v) || !has_edge(u, v)) return false;
    
    adj[u][v] = WEIGHT_MAX;
    if constexpr (!Directed) {
        adj[v][u] = WEIGHT_MAX;
    }
    --edges_;
    return true;
}

template <bool Directed, class WeightType>
bool GraphAdjMat<Directed, WeightType>::has_vertex(size_t v) const {
    return (v < adj.size());
}

template <bool Directed, class WeightType>
bool GraphAdjMat<Directed, WeightType>::has_edge(size_t u, size_t v) const {
    return (adj[u][v] != WEIGHT_MAX);
}

template <bool Directed, class WeightType>
std::vector<size_t> GraphAdjMat<Directed, WeightType>::vertices() const {
    std::vector<size_t> vertices;
    for (size_t r = 0; r < adj.size(); ++r) {
        vertices.push_back(r);
    }
    return vertices;
}

template <bool Directed, class WeightType>
std::vector<size_t> GraphAdjMat<Directed, WeightType>::adj_vertices(size_t v) const {
    std::vector<size_t> vertices;
    if (has_vertex(v)) {
        for (size_t c = 0; c < adj[v].size(); ++c) {
            if (adj[v][c] != WEIGHT_MAX) {
                vertices.push_back(c);
            }
        }
    }
    return vertices;
}

template <bool Directed, class WeightType>
std::pair<size_t, size_t> GraphAdjMat<Directed, WeightType>::size() const {
    return {adj.size(), edges_};
}

template <bool Directed, class WeightType>
void GraphAdjMat<Directed, WeightType>::clear() {
    for (auto& row : adj) {
        row.clear();
    }
}

template <bool Directed, class WeightType>
void GraphAdjMat<Directed, WeightType>::print() const {
    std::cout << "    ";
    for (size_t i = 0; i < adj.size(); ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "   ";
    for (size_t j = 0; j < adj.size(); ++j) {
        std::cout << "--";
    }
    std::cout << std::endl;

    for (size_t r = 0; r < adj.size(); ++r) {
        std::cout << r << " | ";
        for (size_t c = 0; c < adj[0].size(); ++c) {
            if (adj[r][c] == WEIGHT_MAX) {
                std::cout << "M ";
            } else {
                std::cout << adj[r][c] << " ";
            }
        }
        std::cout << std::endl;
    }
}

}   // namespace crs (c. roman [data] structures [library])