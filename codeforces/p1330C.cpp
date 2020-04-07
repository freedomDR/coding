#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;
    vector<int> l(m);
    vector<bool> f(n);
    for(auto &it:l) cin >> it;
    vector<int> ans;
    int ll = 1, i = 0;
    bool can = true, full = false;
    for(auto it:l)
    {
        ans.push_back(min(ll, n-it+1));
        i++;
    }
    if(ll<n) cout << "-1" << endl;
    else
    {
        for(auto it:ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}