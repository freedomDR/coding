#include<bits/stdc++.h>

using namespace std;

int n, m;
int main()
{
    cin >> n >> m;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if(mp.find(v) == mp.end()) mp[v] = i+1;
    }
    for(int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        if(mp.find(v) == mp.end()) cout << "-1 ";
        else cout << mp[v] << " ";
    }
    return 0;
}
