#include <bits/stdc++.h>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include "graph.h"

template void Graph<int>::test();
template std::shared_ptr<Graph<int>> Graph<int>::randomGenerateUndirectedGraph();
template void Graph<int>::printGraph();

template<typename T>
void Graph<T>::test() {
};

template<typename T>
std::shared_ptr<Graph<T>> Graph<T>::randomGenerateUndirectedGraph() {
    std::srand(std::time(NULL));
    int graph_node_size = std::rand()/(RAND_MAX/20);
    std::vector<point_ptr> points;
    for (int i = 0; i < graph_node_size; i++) {
        T point_val = i;
        points.push_back(std::make_shared<Point<T, Edge<T>>>(point_val));
    }
    int graph_edge_size = graph_node_size-1;
    std::vector<edge_ptr> edges;
    for (int i = 0; i < graph_edge_size; i++) {
        int u = std::rand()/(RAND_MAX/graph_node_size);
        int v = std::rand()/(RAND_MAX/graph_node_size);
        std::cout << u << " " << v << std::endl;
        assert(u < graph_node_size);
        assert(v < graph_node_size);
        auto edge = std::make_shared<Edge<T>>(1, EdgeType::undirected, points[u], points[v]);
        edges.push_back(edge);
        points[u]->addEdge(edge);
        points[v]->addEdge(edge);
    }
    return std::make_shared<Graph<T>>(edges, points);
};

template<typename T>
void Graph<T>::printGraph() {
    std::cout << "graph nodes: " << this->points.size() << " edges: " << this->edges.size() << std::endl;
    std::unordered_map<point_ptr, int> pos_map;
    for(int i = 0; i < this->points.size(); i++) {
        pos_map[this->points.at(i)] = i;
    }
    for(int i = 0; i < this->points.size(); i++) {
        if(this->points.at(i)->getEdges().size() == 0) continue;
        std::cout << "node " << i << " -> ";
        for(auto edge:this->points.at(i)->getEdges()) {
            std::cout << pos_map[edge->to] << " ";
        }
        std::cout << std::endl;
    }
}
