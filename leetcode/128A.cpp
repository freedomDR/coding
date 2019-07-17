#include <bits/stdc++.h>

using namespace std;

int bitwiseComplement(int N)
{

    if(N == 0) return 1;
    int ans = 0, c = 1;
    while(N)
    {
        if((N&1) == 0) ans += c;
        c*=2;
        N = N>>1;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    cout<<bitwiseComplement(t)<<endl;
    return 0;
}
