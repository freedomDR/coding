#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<string, vector<int>> m;
    vector<int> cnt(n+1);
    for(int i = 0; i < n-2; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
        m[to_string(a)+"#"+to_string(b)].push_back(c);
        m[to_string(b)+"#"+to_string(a)].push_back(c);
        m[to_string(a)+"#"+to_string(c)].push_back(b);
        m[to_string(c)+"#"+to_string(a)].push_back(b);
        m[to_string(b)+"#"+to_string(c)].push_back(a);
        m[to_string(c)+"#"+to_string(b)].push_back(a);
    }
    int one1 = 0, one2 = 0, two1 = 0, two2 = 0, val = 0;
    for(auto v:cnt) 
    {
        if(v == 1)
        {
            if(one1 == 0) one1 = val;
            else one2 = val;
        }
        if(v == 2)
        {
            if(two1 == 0) two1 = val;
            else two2 = val;
        }
        val++;
    }
    /* cout << one1 << one2 << two1 << two2 << endl; */
    vector<int> ans(n+1), vis(n+1);
    ans[1] = one1; ans[n] = one2;
    if(m.find(to_string(one1)+"#"+to_string(two1)) != m.end())
    {
        ans[2] = two1;
        ans[n-1] = two2;
    }else
    {
        ans[2] = two2;
        ans[n-1] = two1;
    }
    vis[one1] = 1;
    vis[one2] = 1;
    vis[two1] = 1;
    vis[two2] = 1;

    for(int i = 3; i <= n-2; i++)
    {
        auto &tmp = m[to_string(ans[i-1])+"#"+to_string(ans[i-2])];
        for(auto &v:tmp)
        {
            if(vis[v] == 0)
            {
                ans[i] = v;
                vis[v] = 1;
                break;
            }
        }
    }
    for_each(ans.begin()+1, ans.end(), [](const int v) {cout << v << " ";});
    cout << endl;
    return 0;
}
