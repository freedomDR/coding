#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    cout<<((n+1)+n+n+min(k-1, n-k)-1)<<endl;
    return 0;
}
