#include<bits/stdc++.h>

using namespace std;

int n, m, v[31], e[31][31], ans, arr[10];
map<string, int> ind;

void dfs(int nums, int st)
{
    if(nums == 7)
    {
        int sums = 0;
        for(int i = 1; i <= 6; i++) sums += v[arr[i]];
        for(int i = 1; i <= 6; i++)
        {
            for(int j = i; j <= 6; j++)
            {
                sums += e[arr[i]][arr[j]];
            }
        }
        ans = max(ans, sums);
        return;
    }
    for(int i = st; i < n; i++)
    {
        arr[nums] = i;
        dfs(nums+1, i+1);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s >> v[i];
        ind[s] = i;
    }
    for(int i = 0; i < m; i++)
    {
        string s1, s2;
        int val;
        cin >> s1 >> s2 >> val;
        e[ind[s1]][ind[s2]] += val;
        e[ind[s2]][ind[s1]] += val;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}