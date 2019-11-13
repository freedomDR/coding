#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n-1);
    for(auto &it:a) cin >> it;
    long long maxsub = 0, tmp = 0, sums = 0;;
    for(int i = 0; i < n-1; i++)
    {
        tmp += a[i];
        sums += a[i];
        if(i >= k) tmp -= a[i-k];
        maxsub = max(maxsub, tmp);
    }
    cout << sums-maxsub << endl;
    return 0;
}
