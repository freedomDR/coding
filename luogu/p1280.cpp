#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, K; cin >> N >> K;
    vector<pair<int, int>> k(K);
    for(int i = 0; i < K; i++)
    {
        cin >> k[i].first >> k[i].second;
    }
    sort(k.begin(), k.end(), [](auto &k1, auto &k2){return k1.first > k2.first;});
    int pos = 0;
    vector<int> dp(N+5);
    for(int i = N; i >= 1; i--)
    {
        if(pos >= K || k[pos].first != i) dp[i] = dp[i+1]+1;
        else
        {
            while(pos < K && k[pos].first == i)
            {
                dp[i] = max(dp[i], dp[i+k[pos].second]);
                pos++;
            }
        }
    }
    cout << dp[1] << endl;
    return 0;
}
