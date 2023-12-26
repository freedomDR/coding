#include <bits/stdc++.h>
#include <memory>
#include <vector>

enum EdgeType {
    directed,
    undirected
};

template<typename T, typename E>
class Point {
    T val;
    std::vector<std::shared_ptr<E>> edges;

    public:
    Point(T _val): val(_val) {
        edges = std::vector<std::shared_ptr<E>>();
    }
    T getVal() {
        return val;
    }
    void addEdge(std::shared_ptr<E>& edge) {
        edges.push_back(edge);
    }

    const std::vector<std::shared_ptr<E>> getEdges() {
        return edges;
    }
};

template<typename T>
struct Edge {
    T weight;
    EdgeType directed;
    std::shared_ptr<Point<T, Edge<T>>> from;
    std::shared_ptr<Point<T, Edge<T>>> to;
    Edge(T _weight, EdgeType _directed, std::shared_ptr<Point<T, Edge<T>>>& _from, std::shared_ptr<Point<T, Edge<T>>>& _to): weight(_weight), directed(_directed), from(_from), to(_to){}
};

template<typename T>
class Graph {
    using edge_ptr = std::shared_ptr<Edge<T>>;
    using point_ptr = std::shared_ptr<Point<T, Edge<T>>>;
    public:
        static void test();

        static std::shared_ptr<Graph> randomGenerateUndirectedGraph();

        static Graph randomGenerateDirectedGraph();

        Graph(std::vector<edge_ptr>& _edges, std::vector<point_ptr>& _points): edges(_edges), points(_points) {}
        const std::vector<edge_ptr> getEdges() {
            return edges;
        }

        const std::vector<point_ptr> getPoints() {
            return points;
        }

        void printGraph();
    private:
        std::vector<edge_ptr> edges;
        std::vector<point_ptr> points;
};
