#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        priority_queue<int> p;
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            int v; cin >> v;
            if(v != 0)
            {
                p.emplace(v);
                continue;
            }
            if(p.size() == 0) continue;
            ans += p.top();
            p.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
