#include <bits/stdc++.h>
using namespace std;
int h[200050];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, min_h = 200050;
    cin>>n>>k;
    while(n--){
        int tmp;cin>>tmp;h[tmp]++;min_h=min(min_h, tmp);
    }
    int ans = 0, sub_sum = 0, sub_num = 0;
    for(int i = 200000; i > min_h; i--){
        sub_num += h[i];
        if(sub_sum+sub_num > k){
            ans++;
            sub_sum = sub_num;
        }else{
            sub_sum += sub_num;
        }
    } 
    if(sub_sum) ans++;
    cout<<ans<<endl;
    return 0;
}
