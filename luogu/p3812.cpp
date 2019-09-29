#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long> p(61);
    int n; cin >> n;
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        long long v; cin >> v;
        for(int j = 60; j >= 0; j--)
        {
            if(v>>(long long)j == 1)
            {
                if(p[j]) v ^= p[j];
                else
                {
                    p[j] = v;
                    break;  
                }
            }
        }
    }
    for(int i = 60; i >= 0; i--)
    {
        ans  = max(ans, ans^p[i]);
    }
    cout << ans << endl;
}
