//
// Created by shirin dora on 13/04/2020.
//

#ifndef GRAPHS_VERTEX_H
#define GRAPHS_VERTEX_H

#include <string>

struct Vertex {
public:
    std::string label;
    bool visited;

    Vertex (std::string l = "") {
        label = l;
        visited = false;
    }
};

#endif //GRAPHS_VERTEX_H
