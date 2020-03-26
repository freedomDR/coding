#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<bool> p1(n+1, false), p2(n+1, false);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            int k; cin >> k;
            bool f = false;
            for(int j = 1; j <= k; j++)
            {
                int v; cin >> v;
                if(!f&&!p2[v]) {f = true; p2[v] = true;cnt++;}
            }
            if(f) p1[i] = true;
        }
        if(cnt == n) cout << "OPTIMAL" << endl;
        else
        {
            cout << "IMPROVE" << endl;
            int ans1, ans2;
            for(int i = 1; i <= n; i++)
                if(!p1[i]) {ans1 = i;break;}
            for(int i = 1; i <= n; i++)
                if(!p2[i]) {ans2 = i;break;}
            cout << ans1 << " " << ans2 << endl;
        }
        
    }
    return 0;
}