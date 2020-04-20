//
// Created by shirin dora on 13/04/2020.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H


#include "Vertex.h"

class Graph {
public:
    Graph(int size);

    bool add_vertex(std::string l);
    bool add_edge(std::string start_vertex, std::string end_vertex, int weight=1);
    bool remove_edge(std::string start_vertex, std::string end_vertex);
    bool is_adjacent(std::string start_vertex, std::string end_vertex);

    void bfs(std::string start_vertex);
    void dfs(std::string start_vertex);
    void spanning_tree(std::string start_vertex);
private:
    Vertex* vertices;
    int** adj_matrix; // two-dimensional adjacency matrix
    int vertex_count; // number of vertices in the graph
    int vertex_capacity; // maximum number of vertices that can be added

    int find_vertex(std::string l);
    int adjacent_unvisited_vertex(int v);
    void reset_visited_vertices(); // resets visited member variable for all vertices to false
};


#endif //GRAPHS_GRAPH_H
