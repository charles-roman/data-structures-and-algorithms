#ifndef GRAPH_ADJ_MAT_HPP
#define GRAPH_ADJ_MAT_HPP

#include <vector>

namespace crs {

template <bool Directed = false, class WeightType = int>       
class GraphAdjMat {                           
    public:
        // default ctor
        GraphAdjMat();
        // param ctor
        explicit GraphAdjMat(size_t vertices);

        // adds vertex to graph
        void add_vertex();
        // adds edge to graph, returns true if successful
        bool add_edge(size_t u, size_t v, WeightType weight = 1);
        // removes vertex from graph, returns true if successful
        bool remove_vertex(size_t v);
        // removes edge from graph, returns true if successful
        bool remove_edge(size_t u, size_t v);
        // checks if graph contains vertex
        bool has_vertex(size_t v) const;
        // checks if graph contains edge
        bool has_edge(size_t u, size_t v) const;
        // returns list of all vertices
        std::vector<size_t> vertices() const;
        // returns list of adjacent vertices
        std::vector<size_t> adj_vertices(size_t v) const;
        // returns size of graph in pair format G = (V, E)
        std::pair<size_t, size_t> size() const;
        // clears all vertices and edges from graph
        void clear();
        // prints contents of graph in adjacency matrix form
        void print() const;
        
    private:
        WeightType WEIGHT_MAX;
        size_t edges_;
        std::vector<std::vector<WeightType>> adj; // graph (adjacency matrix representation)
        // more data (optional)
};

}   // namespace crs (c. roman [data] structures [library])

#include "graph_adj_mat.tpp"

#endif  // GRAPH_ADJ_MAT_HPP