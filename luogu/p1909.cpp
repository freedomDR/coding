#include <bits/stdc++.h>

using namespace std;

int main()
{
    int need, cost = INT_MAX; cin>>need;
    for(int i = 0; i < 3; i++){
        int n, v; cin>>n>>v;
        cost = min(cost, ((need-1)/n+1)*v);
    }
    cout<<cost<<endl;
    return 0;
}
