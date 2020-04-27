//
// Created by shirin dora on 13/04/2020.
//

#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

#include <iostream>
#include <limits.h>

Graph::Graph (int size) {
    vertex_capacity = size;
    vertices = new Vertex[size];

    // allocate memory for the two-dimensional matrix which is essentially a pointer to array of pointers
    adj_matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        adj_matrix[i] = new int[size];
    }

    // initialize all edges in the graph to zero
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            adj_matrix[i][j] = 0;
        }
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
            std::cout << " -> " << vertices[sv_index].label << " ";
            q.enqueue(sv_index);
        }

        q.dequeue();
    }
    std::cout << std:: endl;

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
            std::cout << " -> " << vertices[sv_index].label << " ";
            stack.push(sv_index);
        }

        stack.pop();
    }
    std::cout << std:: endl;

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

void Graph::shortest_path(std::string start_vertex) {
    // allocate memory for computed distance
    std::string* scanned_vertices = new std::string[vertex_count];
    int* distance = new int[vertex_count];
    bool* scan_flag = new bool[vertex_count];

    // initialize all values in scanned_vertices to "" initially
    for (int i = 0; i < vertex_count; ++i) {
        scanned_vertices[i] = "";
        distance[i] = INT_MAX;
        scan_flag[i] = false;
    }

    // add start_vertex to the array scanned_vertices and set distance to zero
    int sel_vertex = find_vertex(start_vertex);
    scanned_vertices[sel_vertex] = start_vertex;
    distance[sel_vertex] = 0;
    scan_flag[sel_vertex] = true;

    // iterations of the Dijkstra algorithm. In each iteration, distance from source for neighbours of a single vertex
    // is computed
    int vertex_scanned = 1;
    while (vertex_scanned != vertex_count) {
        // scan adjacent vertices and store distances from them
        while (adjacent_unvisited_vertex(sel_vertex) != -1) {
            int v_index = adjacent_unvisited_vertex(sel_vertex);
            scanned_vertices[v_index] = vertices[v_index].label;
            if (distance[v_index] > adj_matrix[sel_vertex][v_index] + distance[sel_vertex]) {
                distance[v_index] = adj_matrix[sel_vertex][v_index] + distance[sel_vertex];
            }
            vertices[v_index].visited = true;
        }
        reset_visited_vertices();

        // find the closest vertex
        int closest_node = -1;
        int min_dist = INT_MAX;
        for (int j = 0; j < vertex_count; ++j) {
            if ((scan_flag[j] == false) && (distance[j] < min_dist)) {
                closest_node = j;
                min_dist = distance[j];
            }
        }

        // update selected vertex
        if (closest_node != -1) {
            sel_vertex = closest_node;
            scan_flag[closest_node] = true;
            vertex_scanned++;
        } else {
            break;
        }
    }

    // print the results
    for (int l = 0; l < vertex_count; ++l) {
        std::cout << scanned_vertices[l] << ": " << distance[l] << ", ";
    }

    delete[] scanned_vertices;
    delete[] distance;
    delete[] scan_flag;
}
