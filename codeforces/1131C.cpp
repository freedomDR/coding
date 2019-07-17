#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    vector<int> ans;
    for(int i = n-1;i >= 0; i--){
        if(i&1) ans.push_back(a[i]);
        else ans.insert(ans.begin(), a[i]);
    }
    for(auto v:ans) cout<<v<<" ";
    return 0;
}
