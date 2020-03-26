#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        long long x = n - (1+2*k-1)*1ll*k/2;
        if(x>=0&&x%2==0) cout << "YES" << endl;  
        else cout << "NO" << endl;
    }
    return 0;
}