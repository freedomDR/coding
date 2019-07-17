#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int w1, h1, w2, h2;
    cin>>w1>>h1>>w2>>h2;
    int ans = (h1+h2)*2+w1+w2+4+(w1-w2);
    cout<<ans<<endl;
    return 0;
}
