#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <queue>
#include <vector>
#include "graph.h"
struct tmp_node {
    int dis;
    int u;
    bool operator>(const tmp_node& v) const {
        return dis > v.dis;
    }
};

void dijkstra(std::shared_ptr<Graph<int>> & graph) {
    int point_sz = graph->getPoints().size();
    std::unordered_map<std::shared_ptr<Point<int, Edge<int>>>, int> pos_map;
    for(int i = 0; i < graph->getPoints().size(); i++) {
        pos_map[graph->getPoints().at(i)] = i;
    }
    std::vector<int> dis(point_sz, 1e9+7);
    dis[0] = 0;
    std::vector<int> vis(point_sz, 0);
    std::priority_queue<tmp_node, std::vector<tmp_node>, std::greater<tmp_node>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        int u = pq.top().u;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto edge:graph->getPoints().at(u)->getEdges()) {
            int v = pos_map[edge->to];
            if(dis[v] > dis[u]+edge->weight) {
                dis[v] = dis[u]+edge->weight;
                pq.push({dis[v], v});
            }
        }
    }
    for(int i = 0; i < point_sz; i++) {
        std::cout << "0 -> " << i << " most short path = " << dis[i] << std::endl;
    }
}

int main(int argc, char *argv[]) {
    auto graph = Graph<int>::randomGenerateUndirectedGraph();
    graph->printGraph();
    dijkstra(graph);
    return 0;
}
