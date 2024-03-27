#include <bits/stdc++.h>

class Graph {
    const int INF = INT_MAX/2;
    vector<vector<int>> g;
    int n;
public:
    Graph(int n_, vector<vector<int>>& edges): n(n_), g(n_, vector<int>(n_, INF)) {
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

int main()
{
    return 0;
}