#include<bits/stdc++.h>
using namespace std;

int cntt[51], N, maxv = 0, minv = 51,sums,ans;

bool dfs(int cnt, int res, int t, int st)
{
    if(cnt == 0) return true;
    if(res == 0)
    {
        return dfs(cnt-1, t, t, maxv);
    }
    bool temp = false;
    for(int i = st; i >= minv; i--)
    {
        if(cntt[i]&&i <= res)
        {
            cntt[i]--;
            temp |= dfs(cnt, res-i, t, i);
            cntt[i]++;
            if(temp == true) break;
            if(res == t || res == i) break;
        }
    }
    return temp;
}

int main()
{
    cin >> N;
    while(N--)
    {
        int v;
        cin >> v;
        if(v <= 50)
        {
            cntt[v]++;
            maxv = max(maxv, v);
            minv = min(minv, v);
            sums+=v;
        }
    }
    ans = sums;
    for(int i = maxv; i <= sums/2; i++)
    {
        if(sums%i == 0)
        {
            bool ok = dfs(sums/i, i, i, maxv);
            if(ok)
            {
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
