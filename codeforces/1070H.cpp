#include <bits/stdc++.h>

using namespace std;
map<string, int> ans;
map<string, string> t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin>>n;
    string s;
    for(int i = 0; i < n; i++){
        cin>>s;
        for(int j = 1; j <= s.length(); j++){
            for(int k = 0; k+j <= s.length(); k++){
                string tmp = s.substr(k, j);
                if(t[tmp] != s)ans[tmp]++;
                t[tmp] = s;
            }
        }
    }
    cin>>q;
    while(q--){
        string tmp;
        cin>>tmp;
        if(ans[tmp] == 0){cout<<"0 -"<<endl;}
        else cout<<ans[tmp]<<" "<<t[tmp]<<endl;
    }
    return 0;
}
