#include <iostream>
#include "graph_adj_list.hpp"

int main(int argc, char* argv[]) {
    // Example: undirected, unweighted, simple graph

    // Declare Graph
    std::cout << "Declaring Graph..." << std::endl;
    crs::GraphAdjList G;

    // Add Vertices
    std::cout << "Adding Vertices..." << std::endl;
    G.add_vertex(1);
    G.add_vertex(2);
    G.add_vertex(3);
    G.add_vertex(4);
    G.add_vertex(5);

    // Add Edges
    std::cout << "Adding Edges..." << std::endl;
    G.add_edge(1, 2);
    G.add_edge(1, 5);
    G.add_edge(2, 5);
    G.add_edge(2, 3);
    G.add_edge(2, 4);
    G.add_edge(3, 4);
    G.add_edge(4, 5);

    // Check Existence of Edge/Vertex and Graph Size
    std::cout << "Vertex 1 Exists: " << (G.has_vertex(1) ? "Yes" : "No") << std::endl;
    std::cout << "Edge (1, 2) Exists: " << (G.has_edge(1, 2) > 0 ? "Yes" : "No") << std::endl;
    std::cout << "Graph Size: (" << G.size().first << ", " << G.size().second << ")" << std::endl;

    // Remove Edge/Vertex
    std::cout << "Removing edge (1, 2)..." << std::endl;
    G.remove_edge(1, 2);
    std::cout << "Removing vertex 1..." << std::endl;
    G.remove_vertex(1);

    // Check Existence of Edge/Vertex and Graph Size
    std::cout << "Vertex 1 Exists: " << (G.has_vertex(1) ? "Yes" : "No") << std::endl;
    std::cout << "Edge (1, 2) Exists: " << (G.has_edge(1, 2) > 0 ? "Yes" : "No") << std::endl;
    std::cout << "Graph Size: (" << G.size().first << ", " << G.size().second << ")" << std::endl;

    // Print
    std::cout << "Printing Graph..." << std::endl;
    G.print();

    exit(EXIT_SUCCESS);
}