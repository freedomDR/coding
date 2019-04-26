#include <bits/stdc++.h>
/*
 *这道题让人感受到绝望。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
 *
 */
using namespace std;

void dfs(vector<vector<pair<int, int>>>& edge, int nums, vector<int>& visit, int n, int current_len, int& ans, int pos)
{
    ans = max(ans, current_len);
    for(auto item:edge[pos])
    {
        if(visit[item.first])
        {
            visit[item.first]--;
            dfs(edge, nums+1, visit, n, current_len+item.second, ans, item.first);
            visit[item.first]++;
        }
    }
}

bool visit[21];
int main()
{
    int n, ans = 0;
    char st;
    cin>>n;
    vector<string> s(n);
    vector<int> visit(n, 2);
    for(int i = 0; i < n; i++) cin>>s[i];
    cin>>st;
    vector<vector<pair<int,int>>> edge(n, vector<pair<int, int>>());
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            int v = INT_MIN;
            for(int k = 1; k < s[i].size(); k++)
            {
                string t1 = s[i].substr(k);
                string t2 = s[j].substr(0, s[i].size()-k);
                if(t1 != t2) continue;
                v = max(v, (int)(s[j].size() - t2.size()));
            }
            if(v != INT_MIN && v != 0) edge[i].push_back(make_pair(j,v));
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(st == s[i][0])
        {
            visit[i]--;
            dfs(edge, 1, visit, n, s[i].size(), ans, i);
            visit[i]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
