#include <bits/stdc++.h>
#include <memory>

enum EdgeType {
    directed,
    undirected
};

template<typename T, typename E>
class Point {
    T val;
    std::shared_ptr<E> to;

    public:
    Point(T _val): val(_val) {}
    Point(T _val, std::shared_ptr<E>& _e): val(_val), to(_e) {}
    T getVal() {
        return val;
    }
};

template<typename T>
struct Edge {
    T weight;
    EdgeType directed;
    Edge(T _weight): weight(_weight) {}
    Edge(T _weight, EdgeType _directed): weight(_weight), directed(_directed){}
};

template<typename T>
class Graph {
    public:
        static void test() {
            std::shared_ptr<Edge<T>> edge = std::make_shared<Edge<T>>(132, EdgeType::undirected);
            std::shared_ptr<Point<T, Edge<T>>> point = std::make_shared<Point<T, Edge<T>>>(1, edge);
            std::cout << point->getVal() << std::endl; 
        };

        /* static Graph randomGenerateUndirectedGraph() { */
        /* }; */

        /* static Graph randomGenerateDirectedGraph() { */
        /* }; */
};

int main()
{
    Graph<int>::test();
    return 0;
}
