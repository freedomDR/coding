#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

int slove(int n, std::vector<std::vector<int>> edges, std::vector<int>  r)
{
    auto time_1 = std::chrono::high_resolution_clock::now();
    int cnt = 0;
    std::vector<bool> visit(n, false);
    for(auto v:r)
        visit[v] = true;
    std::vector<std::set<int>> new_edges(n);
    for(auto & e:edges)
    {
        int u = e[0], v = e[1];
        new_edges[u].insert(v);
        new_edges[v].insert(u);
    }
    std::queue<int> q;
    q.push(0);
    visit[0] = true;
    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        cnt++;
        for(auto v:new_edges[i])
        {
            if(!visit[v])
            {
                q.push(v);
                visit[v] = true;
            }
        }
    }
    auto time_2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> cost = time_2-time_1;
    std::cout << "cost " << cost.count() << "ms\n";
    return cnt;
}

int main()
{
    std::cout << slove(7, {{0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6}}, {4,5}) << "\n";
    std::cout << slove(7, {{0, 1}, {0, 2}, {0, 4}, {0, 5}, {3, 2}, {6, 5}}, {4,2,1}) << "\n";
    return 0;
}