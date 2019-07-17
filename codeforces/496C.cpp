#include <bits/stdc++.h>

using namespace std;
const int N = 200010;
char s[N];
queue<int> q0,q1;
vector<int> ans[N];
int len, k;
int main()
{
    scanf("%s", s+1);
    len = strlen(s+1);
    for(int i = 1; i <= len; i++){
        if(s[i] == '1'){
            if(q0.empty()){
                cout<<"-1"<<endl;return 0;
            }
            int num = q0.front();q0.pop();q1.push(num);
            ans[num].push_back(i);
        }else{
            if(q1.empty()){
                k++;
                q0.push(k);
                ans[k].push_back(i);
            }else{
                int num = q1.front();q1.pop();q0.push(num);
                ans[num].push_back(i);
            }
        }
    }
    if(!q1.empty()){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<k<<endl;
    for(int i = 1; i <= k; i++){
        if(ans[i].size() == 0) break;
        cout<<ans[i].size();
        for(auto& xx:ans[i]) cout<<" "<<xx;
        cout<<endl;
    }
    return 0;
}
