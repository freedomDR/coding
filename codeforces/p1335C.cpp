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
        vector<int> cnt(n+1);
        for(int i = 0; i < n; i++)
        {
            int v;
            cin >> v; cnt[v]++;
        }
        if(n == 1) 
        {
            cout << "0" << endl;
            continue;
        }
        int diff = 0, same = 0, maxs = 0;
        for(int i = 1; i <= n; i++)
        {
            if(cnt[i] == 1) diff++;
            if(cnt[i] > 1)
            {
                same++;
                maxs = max(cnt[i], maxs);
            }
        }
        if(same == 0)
        {
            cout << "1" << endl;
            continue;
        }
        diff += same-1;
        if(maxs >= diff+2) {diff += 1; maxs -= 1;}
        cout << min(diff, maxs) << endl;
    }
    return 0;
}