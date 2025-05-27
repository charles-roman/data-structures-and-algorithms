#include <iostream>
#include "graph_adj_mat.hpp"

int main(int argc, char* argv[]) {
    // Declare Graph
    std::cout << "Declaring Graph..." << std::endl;
    crs::GraphAdjMat G(4);

    // Add Vertices
    std::cout << "Adding Vertices..." << std::endl;
    G.add_vertex();
    G.add_vertex();

    // Add Edges
    std::cout << "Adding Edges..." << std::endl;
    G.add_edge(0, 1);
    G.add_edge(0, 4);
    G.add_edge(1, 2);
    G.add_edge(1, 3);
    G.add_edge(1, 4);
    G.add_edge(2, 3);
    G.add_edge(3, 4);

    // Check Existence of Edge and Graph Size
    std::cout << "Graph Size: (" << G.size().first << ", " << G.size().second << ")" << std::endl;
    std::cout << "Edge (1, 2) Exists: " << (G.has_edge(1, 2) ? "Yes" : "No") << std::endl;

    // Remove Edge/Vertex
    std::cout << "Removing edge (1, 2)..." << std::endl;
    G.remove_edge(1, 2);
    std::cout << "Removing vertex..." << std::endl;
    G.remove_vertex(5);

    // Check Existence of Edge and Graph Size
    std::cout << "Graph Size: (" << G.size().first << ", " << G.size().second << ")" << std::endl;
    std::cout << "Edge (1, 2) Exists: " << (G.has_edge(1, 2) ? "Yes" : "No") << std::endl;

    // Print
    std::cout << "Printing Graph..." << std::endl;
    G.print();

    exit(EXIT_SUCCESS);
}