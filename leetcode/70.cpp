#include<bits/stdc++.h>
using namespace std;

int get(int p, vector<int>& dp)
{
    if(dp[p] != -1) return dp[p];
    else return dp[p]=get(p-1, dp)+get(p-2, dp);
}

int slove(int n)
{
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    return get(n, dp);
}

int main()
{
    int n;
    cin >> n;
    cout << slove(n) << endl;
    return 0;
}
