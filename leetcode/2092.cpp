#include <bits/stdc++.h>

using namespace std;

int findFa(int x, vector<int> & fa);
void unionFa(int x, int y, vector<int> & fa);

void slove(int n, vector<vector<int>> & meetings, int fi)
{
    vector<int> fa(n);
    for(int i = 0; i < n; i++)
        fa[i] = i;
    map<int, vector<vector<int>>> mp;
    for(auto meet:meetings)
    {
        mp[meet.at(2)].push_back(meet);
    }
    fa[fi] = 0;
    for(auto v:mp)
    {
        for(auto vv:v.second)
        {
            if(findFa(vv[0], fa) == 0)
                unionFa(vv[0], vv[1], fa);
            else if(findFa(vv[1], fa) == 0)
                unionFa(vv[1], vv[0], fa);
        }
    }
    vector<int> ret;
    for(int i = 0; i < n; i++)
    {
        if(findFa(i, fa) == 0)
            ret.push_back(i);
    }
    for(auto v:ret) 
        cout << v << endl;
}

int findFa(int x, vector<int> & fa)
{
    if(x != fa[x])
        fa[x] = findFa(fa[x], fa);
    return fa[x];
}

void unionFa(int x, int y, vector<int> & fa)
{
    int fx = findFa(x, fa);
    int fy = findFa(y, fa);
    if(fx != fy)
        fa[y] = fx;
}

int main()
{
    int n = 6;
    int fi = 1;
    vector<vector<int>> meetings = {{0,2,1}, {1,3,1}, {4,5,1}};
    slove(n, meetings, fi);
    return 0;
}