#include <bits/stdc++.h>

using namespace std;
int a[1050], x[1050];
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int k = 1;
    vector<int> ans;
    while(k <= n){
        memset(x, 0, sizeof(x));
        int check = 1;
        for(int i = 0; i < k; i++){
            x[i] = a[i+1] - a[i];
        }
        for(int j = k+1; j <= n; j++){
            if(a[j] != x[(j-1)%k]+a[j-1]){check = 0;break;}
        }
        if(check) ans.push_back(k);
        k++;
    }
    cout<<ans.size()<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}
