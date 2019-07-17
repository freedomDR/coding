#include <bits/stdc++.h>

using namespace std;
int f[] = {0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0};
int n;
vector<int> ans;
void product(int l){
    int start = 1;
    if(l == n){
        for(auto t: ans){
            cout<<t<<" ";
        }
        cout<<endl;
    }
    if(ans[l-1]%2 == 1)start = 2;
    for(;start <= n; start+=2){
        if(f[start] == 0){
            ans.push_back(start);
            f[start] = 1;
            product(l+1);
            f[start]=0;
            ans.pop_back();
        }
    }
}
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++){
        ans.push_back(i);f[i] = 1;
        product(1);
        ans.pop_back();f[i] = 0;
    }
    return 0;
}
