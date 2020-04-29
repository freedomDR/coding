#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n; 
    vector<long long> a(n);
    for(auto &it:a) cin >> it;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for(auto &it:a) q.push(it);
    long long ans = 0;
    while(q.size() > 1)
    {
        int q1 = q.top();q.pop();
        int q2 = q.top();q.pop();
        ans += q1+q2;
        q.push(q1+q2);
    }
    cout << ans << endl;
    return 0;
}