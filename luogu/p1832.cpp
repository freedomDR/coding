#include<bits/stdc++.h>

using namespace std;

long long dp[1010];
int n;
bool isPrime[1010];
int main()
{
    isPrime[1] = true;
    for(int i = 2; i < 1001; i++)
    {
        if(isPrime[i]) continue;
        for(int j = i+i; j < 1001; j+=i)
            isPrime[j] = true;
    }
    vector<int> prime;
    cin >> n;
    for(int i = 1; i <= n; i++)
        if(!isPrime[i]) prime.push_back(i);
    dp[0] = 1;
    for(int i = 0; i < prime.size(); i++)
    {
        for(int j = 0; j+prime[i] <= n; j++)
        {
            dp[j+prime[i]] += dp[j];
        }
    }
    cout << dp[n] << endl;
    return 0;
}