#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <vector>
#include "graph.h"

void floyd(std::shared_ptr<Graph<int>> & graph) {
    int point_sz = graph->getPoints().size();
    std::vector<std::vector<int>> f(point_sz, std::vector<int>(point_sz, RAND_MAX/2));
    std::unordered_map<std::shared_ptr<Point<int, Edge<int>>>, int> pos_map;
    for(int i = 0; i < graph->getPoints().size(); i++) {
        pos_map[graph->getPoints().at(i)] = i;
    }
    for(int i = 0; i < graph->getPoints().size(); i++) {
        if(graph->getPoints().at(i)->getEdges().size() == 0) continue;
        for(auto edge:graph->getPoints().at(i)->getEdges()) {
            int u = i, v = pos_map[edge->to];
            f[u][v] = edge->weight;
            f[v][u] = edge->weight;
        }
    }
    for(auto point:graph->getPoints()) {
    }
    for(int k = 0; k < point_sz; k++) {
        for(int i = 0; i < point_sz; i++) {
            for(int j = 0; j < point_sz; j++) {
                f[i][j] = std::min(f[i][j], f[i][k]+f[k][j]);
            }
        }
    }
    for(int i = 0; i < point_sz; i++) {
        for(int j = i+1; j < point_sz; j++) {
            std::cout << i << " -> " << j << " most path = " << f[i][j] << std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    auto graph = Graph<int>::randomGenerateUndirectedGraph();
    graph->printGraph();
    floyd(graph);
    return 0;
}
