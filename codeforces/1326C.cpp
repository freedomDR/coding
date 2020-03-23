#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(auto &it:p) cin >> it;
    long long sums = 0, nums = 1;
    int pre = -1;
    for(int i = 0; i < n; i++)
    {
        if(p[i]>=n-k+1)
        {
            sums += p[i];
            if(pre!=-1)
                nums *= (i-pre)*1ll;
            nums %= 998244353ll;
            pre = i;
        }
    }
    cout << sums << " " << nums << endl;
    return 0;
}