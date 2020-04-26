#include<bits/stdc++.h>

using namespace std;
int v, n, c;
int vs[10001], cs[10001], dp[10001]; 

int main()
{
    cin >> v >> n >> c;
    for(int i = 1; i <= n; i++) cin >> vs[i] >> cs[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = c; j >= cs[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-cs[i]]+vs[i]);
        }
    }
    int pos = 1;
    while(pos <= c && dp[pos] < v) pos++;
    if(pos == c+1) cout << "Impossible" << endl;
    else cout << (c-pos) << endl;
    return 0;
}