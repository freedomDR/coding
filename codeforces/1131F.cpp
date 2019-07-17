#include<bits/stdc++.h>

using namespace std;
const int N = 15e4 + 1000;
int father[N], link[N], last[N];
int find(int x)
{
    if(x == father[x]) return x;
    return father[x] = find(father[x]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, x, y;
    cin>>n;
    for(int i = 1; i <= n; i++) father[i]=last[i]=i;
    for(int i = 1; i < n; i++)
    {
        cin>>x>>y;
        int fx = find(x);
        int fy = find(y);
        father[fx] = fy;
        link[last[fy]] = fx;
        last[fy] = last[fx];
    }
    for(int i = 1; i <= n; i++)
    {
        if(father[i] == i)
        {
            int next_v = i;
            while(next_v)
            {
                cout<<next_v<<" ";
                next_v = link[next_v];
            }
        }
    }
    return 0;
}
