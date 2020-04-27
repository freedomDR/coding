#include<bits/stdc++.h>

using namespace std;

const int maxn = 201;
int main()
{
    vector<int> nums(maxn), ans(maxn),prime;
    for(int i = 2; i < maxn; i++)
    {
        if(nums[i]==0) prime.push_back(i);
        for(int j = 0; j < (int)prime.size(); j++)
        {
            if(i*prime[j]>=maxn) break;
            nums[i*prime[j]] = 1;
            if(i%prime[j] == 0) break; 
        }
    }
    ans[0] = 1;
    for(int i = 0; i < (int)prime.size(); i++)
    {
        for(int j = 0; j+prime[i]<maxn; j++)
        {
            ans[j+prime[i]] += ans[j];
        }
    }
    int n;
    while(cin >> n)
    {
        cout << ans[n] << endl;
    }
    return 0;
}