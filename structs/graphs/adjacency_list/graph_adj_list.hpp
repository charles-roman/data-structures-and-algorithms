#ifndef GRAPH_ADJ_LIST_HPP
#define GRAPH_ADJ_LIST_HPP

#include <unordered_map>
#include <vector>
#include <list>

namespace crs {

template <class WeightType = int>       
class GraphAdjList {                           
    public:
        // default ctor
        GraphAdjList();

        // adds vertex to graph, returns true if successful
        bool add_vertex(size_t v);
        // adds edge to graph, returns true if successful
        bool add_edge(size_t u, size_t v, bool dir = false, WeightType weight = 1);
        // removes vertex from graph, returns true if successful
        bool remove_vertex(size_t v);
        // removes edge(s) from graph, returns count of removed edges
        size_t remove_edge(size_t u, size_t v, bool dir = false, WeightType weight = 1);
        // checks if graph contains vertex
        bool has_vertex(size_t v) const;
        // returns number of edges that meet input criteria
        size_t has_edge(size_t u, size_t v, bool dir = false, WeightType weight = 1) const;
        // returns list of all vertices
        std::vector<size_t> vertices() const;
        // returns list of adjacent vertices
        std::vector<size_t> adj_vertices(size_t v) const;
        // returns size of graph in pair format G = (V, E)
        std::pair<size_t, size_t> size() const;
        // clears all vertices and edges from graph
        void clear();
        // prints contents of graph in adjacency list form
        void print() const;

        // clear vertex
        // list vertices
        // list edges
        // list adjacent vertices
        // list in edges
        // list out edges
        // list edges incident on vertex
        // list vertices connected to edge
        // source/destination vertex of edge
        // degree of vertex
        // in/out degree of vertex

    private:
        struct Edge {
            Edge() = default;
            Edge(size_t dest, bool dir, WeightType weight) 
                : dest_(dest), dir_(dir), weight_(weight) {}
            
            friend bool operator==(const Edge& left, const Edge& right) {
                return (left.dest_ == right.dest_ &&
                        left.dir_ == right.dir_ &&
                        left.weight_ == right.weight_);
            }

            bool dir_;          // directed
            size_t dest_;       // destination (vertex)
            WeightType weight_; // weight
            // more data (optional)
        };

        size_t edges_;
        std::unordered_map<size_t, std::list<Edge>> adj; // graph (adjacency list representation)
        // more data (optional)
};

}   // namespace crs (c. roman [data] structures [library])

#include "graph_adj_list.tpp"

#endif  // GRAPH_ADJ_LIST_HPP