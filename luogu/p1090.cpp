#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> a;
    for(int i = 0; i < n; i++)
    {
        int v;
        cin>>v;
        a.push(v);
    }
    long long ans = 0;
    while(a.size() != 1)
    {
        int v1 = a.top();
        a.pop();
        int v2 = a.top();
        a.pop();
        ans += v1+v2;
        a.push(v1+v2);
    }
    cout<<ans<<endl;
    return 0;
}
