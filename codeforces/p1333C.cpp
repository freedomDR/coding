#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &it:a) cin >> it;
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        long long sums = 0;
        for(int j = i; j < n; j++)
        {
            sums += a[j];
            if(sums == 0) {ans -= i;break;}
            ans++;   
        }
    }
    cout << ans << endl;
    return 0;
}