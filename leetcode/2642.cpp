#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <memory>
#include <queue>

using namespace std;

class Graph1 {
    const int INF = INT_MAX/2;
    vector<vector<int>> g;
    int n;
public:
    Graph1(int n_, vector<vector<int>>& edges): n(n_), g(n_, vector<int>(n_, INF)) {
        for(auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            g[u][v] = c;
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dis(n, INF);
        vector<bool> vis(n, false);
        dis[node1] = 0;
        while(true)
        {
            int min_node = -1;
            for(int i = 0; i < n; i++)
            {
                if(!vis[i]&&dis[i]!=INF&&(min_node==-1||dis[i]<dis[min_node]))
                    min_node = i;
            }
            if(min_node == node2) return dis[min_node];
            if(min_node == -1) break;
            vis[min_node] = true;
            for(int i = 0; i < n; i++)
            {
                if(g[min_node][i]!=INF&&!vis[i])
                    dis[i] = min(dis[i], dis[min_node]+g[min_node][i]);
            }
        }
        return -1;
    }
};

class Graph2 {

    using pii = pair<int, int>;
    vector<vector<pii>> e;
    int n;
public:
    Graph2(int n_, vector<vector<int>> & edges): n(n_), e(n_, vector<pii>())
    {
        for(auto & v: edges)
        {
            e[v[0]].push_back({v[1], v[2]});
        }
    }

    void addEdge(vector<int> edge)
    {
        e[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        vector<int> dis(n, INT_MAX);
        priority_queue<pii, vector<pii>, std::greater<pii>> pq;
        pq.push({0, node1});
        dis[node1] = 0;
        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();
            if(node == node2)
                return d;
            if(d > dis[node])
                continue;
            for(auto & [v, c] : e[node])
            {
                if(dis[v] > d+c)
                {
                    dis[v] = d+c;
                    pq.push({dis[v], v});
                }
            }
        }
        return -1;
    }

};

class Graph3 {
    vector<vector<int>> f;
    int n;
public:
    Graph3(int n_, vector<vector<int>> & edges): n(n_), f(n_, vector<int>(n_, INT_MAX))
    {
        for(int i = 0; i < n; i++)
            f[i][i] = 0;
        for(auto & v:edges)
            f[v[0]][v[1]] = v[2];
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                if(f[i][k] == INT_MAX) continue;
                for(int j = 0; j < n; j++)
                    if(f[k][j] != INT_MAX)
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    void addEdge(vector<int> edge)
    {
        if(edge[2] >= f[edge[0]][edge[1]])
            return;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(f[i][edge[0]]!=INT_MAX&&f[edge[1]][j]!=INT_MAX)
                    f[i][j] = min(f[i][j], f[i][edge[0]]+edge[2]+f[edge[1]][j]);
            }
        }
    }

    int shortestPath(int node1, int node2)
    {
        if(f[node1][node2] == INT_MAX) return -1;
        else return f[node1][node2];
    }

};
int main()
{
    vector<vector<int>> arr = {{0,2,5},{0,1,2},{1,2,1},{3,0,3}};
    auto g1 = std::make_shared<Graph1>(4, arr);
    cout << g1->shortestPath(3, 2) << endl;
    cout << g1->shortestPath(0, 3) << endl;
    g1->addEdge({1, 3, 4});
    cout << g1->shortestPath(0, 3) << endl;
    auto g2 = std::make_shared<Graph2>(4, arr);
    cout << g2->shortestPath(3, 2) << endl;
    cout << g2->shortestPath(0, 3) << endl;
    g2->addEdge({1, 3, 4});
    cout << g2->shortestPath(0, 3) << endl;
    auto g3 = std::make_shared<Graph3>(4, arr);
    cout << g3->shortestPath(3, 2) << endl;
    cout << g3->shortestPath(0, 3) << endl;
    g3->addEdge({1, 3, 4});
    cout << g3->shortestPath(0, 3) << endl;
    return 0;
}