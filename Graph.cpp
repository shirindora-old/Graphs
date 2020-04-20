//
// Created by shirin dora on 13/04/2020.
//

#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

#include <iostream>

Graph::Graph (int size) {
    vertex_capacity = size;
    vertices = new Vertex[size];

    // allocate memory for the two-dimensional matrix which is essentially a pointer to array of pointers
    adj_matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        adj_matrix[i] = new int[size];
    }

    vertex_count = 0;
}

bool Graph::add_vertex(std::string l) {
    if (vertex_count < vertex_capacity) {
        vertices[vertex_count] = Vertex(l);
        vertex_count++;
        return true;
    }

    return false;
}

// Post: an edge is created between two vertices in the graph
bool Graph::add_edge(std::string start_vertex, std::string end_vertex, int weight) {
    int sv_index = find_vertex(start_vertex);
    int ev_index = find_vertex(end_vertex);
    if (sv_index != -1 && ev_index != -1) {
        adj_matrix[sv_index][ev_index] = weight;
        return true;
    }

    return false;
}

int Graph::find_vertex(std::string l) {
    for (int i = 0; i < vertex_count; ++i) {
        if (vertices[i].label == l) {
            return i;
        }
    }

    return -1;
}

bool Graph::is_adjacent(std::string start_vertex, std::string end_vertex) {
    int sv_index = find_vertex(start_vertex);
    int ev_index = find_vertex(end_vertex);

    return adj_matrix[sv_index][ev_index] > 0;
}

void Graph::bfs(std::string start_vertex) {
    Queue q;
    int sv_index = find_vertex(start_vertex);

    vertices[sv_index].visited = true;
    std::cout << "BFS: " << vertices[sv_index].label << " ";
    q.enqueue(sv_index);

    while (!q.is_empty()) {
        while (adjacent_unvisited_vertex(q.peek()) != -1) {
            sv_index = adjacent_unvisited_vertex(q.peek());
            vertices[sv_index].visited = true;
            std::cout << "BFS: " << vertices[sv_index].label << " ";
            q.enqueue(sv_index);
        }

        q.dequeue();
    }

    reset_visited_vertices();
}

void Graph::reset_visited_vertices() {
    for (int i = 0; i < vertex_count; ++i) {
        vertices[i].visited = false;
    }
}

void Graph::dfs(std::string start_vertex) {
    Stack stack;
    int sv_index = find_vertex(start_vertex);

    vertices[sv_index].visited = true;
    std::cout << "DFS: " << vertices[sv_index].label << " ";
    stack.push(sv_index);

    while (!stack.is_empty()) {
        while (adjacent_unvisited_vertex(stack.top()) != -1) {
            sv_index = adjacent_unvisited_vertex(stack.top());
            vertices[sv_index].visited = true;
            std::cout << "DFS: " << vertices[sv_index].label << " ";
            stack.push(sv_index);
        }

        stack.pop();
    }

    reset_visited_vertices();
}

int Graph::adjacent_unvisited_vertex(int v) {
    for (int i = 0; i < vertex_count; ++i) {
        if ((adj_matrix[v][i] != 0) && (vertices[i].visited == false)) {
            return i;
        }
    }
    
    return -1;
}

void Graph::spanning_tree(std::string start_vertex) {

}
