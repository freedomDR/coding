#include <bits/stdc++.h>
#include <compare>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <queue>
#include <vector>
#include "graph.h"

void bellmanFord(std::shared_ptr<Graph<int>> & graph) {
    int point_sz = graph->getPoints().size();
    std::unordered_map<std::shared_ptr<Point<int, Edge<int>>>, int> pos_map;
    for(int i = 0; i < graph->getPoints().size(); i++) {
        pos_map[graph->getPoints().at(i)] = i;
    }
    std::vector<int> dis(point_sz, 1e9+7);
    dis[0] = 0;
    for(int i = 0; i < point_sz; i++) {
        bool flag = false;
        for(int u = 0; u < point_sz; u++) {
            if(dis[u] == 1e9+7) continue;
            for(auto edge:graph->getPoints().at(u)->getEdges()) {
                int v = pos_map[edge->to];
                if(dis[v] > dis[u]+edge->weight) {
                    dis[v] = dis[u]+edge->weight;
                    flag = true;
                }
            }
        }
        if(!flag) break;
    }
    for(int i = 0; i < point_sz; i++) {
        std::cout << "0 -> " << i << " most short path = " << dis[i] << std::endl;
    }
}
void spfa(std::shared_ptr<Graph<int>> & graph) {
    int point_sz = graph->getPoints().size();
    std::unordered_map<std::shared_ptr<Point<int, Edge<int>>>, int> pos_map;
    for(int i = 0; i < graph->getPoints().size(); i++) {
        pos_map[graph->getPoints().at(i)] = i;
    }
    std::vector<int> dis(point_sz, 1e9+7), vis(point_sz, 0);
    dis[0] = 0;
    std::queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(auto edge:graph->getPoints().at(u)->getEdges()) {
            int v = pos_map[edge->to];
            if(dis[v] > dis[u]+edge->weight) {
                dis[v] = dis[u]+edge->weight;
                if(!vis[v])
                    vis[v] = true, q.push(v);
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
    bellmanFord(graph);
    spfa(graph);
    return 0;
}
