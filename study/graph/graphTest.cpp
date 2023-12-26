#include <bits/stdc++.h>
#include "graph.h"

int main(int argc, char *argv[])
{
    Graph<int>::test();
    auto undirected_graph = Graph<int>::randomGenerateUndirectedGraph();
    auto points = undirected_graph->getPoints();
    undirected_graph->printGraph();
    return 0;
}
