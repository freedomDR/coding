#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> q;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    while(m-- > 0)
    {
        int a = q.top();
        a /= 2;
        q.pop();
        q.push(a);
    }
    long long ans = 0;
    while(!q.empty())
    {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}
