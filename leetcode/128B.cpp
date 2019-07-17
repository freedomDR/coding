#include <bits/stdc++.h>

using namespace std;

int numPairsDivisibleBy60(vector<int>& time)
{
    vector<int> time_sum(61, 0);
    for(auto item:time)
    {
        time_sum[item%60]++;
    }
    long long ans = 0;
    for(int i = 1; i < 30; i++)
    {
        ans += time_sum[i]*time_sum[60-i];
    }
    long long temp = 0;
    time_sum[30]--;
    time_sum[0]--;
    while(time_sum[30] > 0)
    {
        temp += time_sum[30];
        time_sum[30]--;
    }
    ans += temp; temp = 0;
    while(time_sum[0] > 0)
    {
        temp += time_sum[0];
        time_sum[0]--;
    }
    ans += temp;
    return ans;
}

int main()
{
    int n;cin>>n;
    vector<int> time(n);
    for(int i = 0; i < n; i++) cin>>time[i];
    cout<<numPairsDivisibleBy60(time)<<endl;
    return 0;
}
