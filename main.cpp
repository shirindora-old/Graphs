#include <iostream>
#include "Graph.h"

int main() {
    Graph g;
    g.add_vertex("BFS"); // Belfast
    g.add_vertex("LHR"); // Heathrow
    g.add_vertex("AMS"); // Amsterdam
    g.add_vertex("PRG"); // Prague
    g.add_vertex("MUC"); // Munich
    g.add_vertex("ATH"); // Athens
    g.add_vertex("DEL"); // Delhi
    g.add_vertex("CDG"); // Paris
    g.add_vertex("BCN"); // Barcelona
    g.add_vertex("FCO"); // Rome
    g.add_vertex("SIN"); // Singapore
    g.add_vertex("SYD"); // Sydney

    g.add_edge("BFS", "LHR", 10);
    g.add_edge("BFS", "AMS", 20);
    g.add_edge("LHR", "AMS", 14);
    g.add_edge("LHR", "CDG", 7);
    g.add_edge("AMS", "PRG", 2);
    g.add_edge("AMS", "DEL", 33);
    g.add_edge("CDG", "BCN", 18);
    g.add_edge("AMS", "MUC", 6);
    g.add_edge("CDG", "FCO", 12);
    g.add_edge("MUC", "ATH", 7);
    g.add_edge("DEL", "SIN", 18);
    g.add_edge("SIN", "SYD", 21);

    g.bfs("BFS");
    g.dfs("BFS");
    g.shortest_path("BFS");
}
