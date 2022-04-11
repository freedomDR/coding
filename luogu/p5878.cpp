#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n), ans(n);
    for(auto &v:arr)
        cin >> v;
    stack<int> s;
    arr.push_back(-0x7FFFFFFF);
    for(int i = 0; i < arr.size(); i++)
    {
        while(!s.empty() && arr[s.top()] < arr[i])
        {
            ans[s.top()] = i+1==n+1?0:i+1;
            s.pop();
        }
        s.push(i);
    }
    for(auto v:ans)
        cout << v << " ";
    cout << endl;
    return 0;
}
