#include <bits/stdc++.h>
#include "graph.h"

int main(int argc, char *argv[])
{
    Graph<int>::test();
    auto undirected_graph = Graph<int>::randomGenerateUndirectedGraph();
    auto points = undirected_graph->getPoints();
    for(auto point:points) {
        std::cout << "point val: " << point->getVal() << std::endl;
    }
    auto edges = undirected_graph->getEdges();
    for(auto edge:edges) {
        std::cout << "edge from " << edge->from->getVal() << " to " << edge->to->getVal() << " type: " << edge->directed << " weight: " << edge->weight << std::endl;
    }
    undirected_graph->printGraph();
    return 0;
}
