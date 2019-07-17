#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,v;
    string s;
    unordered_map<string, int> a, b;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        if(a.find(s) == a.end()){
            a[s] = 1;
        }else{
            a[s]++;
        }
    }
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>s;
        if(b.find(s) == b.end()){
            b[s] = 1;
        }else{
            b[s]++;
        }
    }
    int ans = 0;
    for(auto& x:a){
        if(b.find(x.first) != b.end()){
            auto mid = b.find(x.first);
            ans = max(ans, x.second-mid->second);
        }else{
            ans = max(ans, x.second);
        }
    }
    cout<<ans<<endl;
    return 0;
}
