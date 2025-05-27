#include <iostream>
#include "graph.hpp"

int main(int argc, char* argv[]) {

    // Declare Graph (Adj-List)
    crs::GraphAdjList G;

    // Add Vertices
    G.add_vertex(1);
    G.add_vertex(2);
    G.add_vertex(3);
    G.add_vertex(4);
    G.add_vertex(5);

    // Add Edges
    G.add_edge(1, 2);
    G.add_edge(1, 5);
    G.add_edge(2, 5);
    G.add_edge(2, 3);
    G.add_edge(2, 4);
    G.add_edge(3, 4);
    G.add_edge(4, 5);

    // Declare Graph (Adj-Mat)
    crs::GraphAdjMat g(5);

    // Add Edges
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    // Declare Auxiliary Data Structs
    std::unordered_map<size_t, int> distance;
    std::unordered_map<size_t, size_t> predecessor;
    std::unordered_map<size_t, std::pair<size_t, size_t>> time;
    std::vector<int> dist;
    std::vector<size_t> pred;
    std::vector<std::pair<size_t, size_t>> T;

    // Run Breadth-First Search
    cra::bfs(G, 1, distance, predecessor);  // adj_list
    cra::bfs(g, 0, dist, pred);  // adj_mat

    // Display Results
    std::cout << "BFS on adjacency-list graph..." << std::endl;

    for (const auto& [v, d] : distance) {
        std::cout << "vertex " << v << " distance from source: " << d << std::endl;
    }

    for (const auto& [v, p] : predecessor) {
        std::string str = (p == SIZE_MAX ? "N/A" : std::to_string(p));
        std::cout << "vertex " << v << " parent: " << str << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    std::cout << "BFS on adjacency-matrix graph..." << std::endl;

    for (size_t i = 0; i < dist.size(); ++i) {
        std::cout << "vertex " << i << " distance from source: " << dist[i] << std::endl;
    }

    for (size_t j = 0; j < dist.size(); ++j) {
        std::string str = (pred[j] == SIZE_MAX ? "N/A" : std::to_string(pred[j]));
        std::cout << "vertex " << j << " parent: " << str << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    // Run Depth-First Search
    cra::dfs(G, predecessor, time);  // adj_list
    cra::dfs_stk(G, predecessor, time); // adj_list w/ stack
    cra::dfs(g, pred, T);  // adj_mat

    // Display Results
    std::cout << "DFS on adjacency-list graph..." << std::endl;

    for (const auto& [v, p] : predecessor) {
        std::string str = (p == SIZE_MAX ? "N/A" : std::to_string(p));
        std::cout << "vertex " << v << " parent: " << str << std::endl;
    }

    for (const auto& [v, t] : time) {
        std::cout << "vertex " << v << " discovery time: " << t.first << std::endl;
        std::cout << "vertex " << v << " finish time: " << t.second << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    std::cout << "DFS on adjacency-matrix graph..." << std::endl;

    for (size_t k = 0; k < pred.size(); ++k) {
        std::string str = (pred[k] == SIZE_MAX ? "N/A" : std::to_string(pred[k]));
        std::cout << "vertex " << k << " parent: " << str << std::endl;
    }

    for (size_t m = 0; m < T.size(); ++m) {
        std::cout << "vertex " << m << " discovery time: " << T[m].first << std::endl;
        std::cout << "vertex " << m << " finish time: " << T[m].second << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    // Clear Graph
    G.clear();

    // Rebuild Graph as DAG
    // Add Vertices
    G.add_vertex(1);
    G.add_vertex(2);
    G.add_vertex(3);
    G.add_vertex(4);
    G.add_vertex(5);
    G.add_vertex(6);
    G.add_vertex(7);
    G.add_vertex(8);
    G.add_vertex(9);

    // Add Edges
    G.add_edge(1, 4, true);
    G.add_edge(2, 3, true);
    G.add_edge(2, 4, true);
    G.add_edge(3, 4, true);
    G.add_edge(3, 7, true);
    G.add_edge(6, 7, true);
    G.add_edge(6, 8, true);
    G.add_edge(7, 9, true);
    G.add_edge(8, 9, true);

    // Declare Auxiliary Data Structs
    std::forward_list<size_t> list;

    // Run DFS
    cra::dfs(G, predecessor, time);

    // Run Topological Sort
    cra::topo_sort(G, list);

    // Display Results
    std::cout << "DFS on DAG..." << std::endl;

    for (const auto& [v, t] : time) {
        std::cout << "vertex " << v << " finish time: " << t.second << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    std::cout << "Topological Sort on DAG..." << std::endl;

    std::cout << "Topologically Sorted Vertices: ";
    for (const size_t v : list) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;

    exit(EXIT_SUCCESS);
}