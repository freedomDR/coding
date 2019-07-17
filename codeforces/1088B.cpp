#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    for(int i = 0, j = 0, pre_sum = 0; i < k; i++){
        if(j == 0) {cout<<a[i]<<endl; pre_sum = a[i]; j++;}
        else if(j < n){
            while(j < n && a[j] == a[j-1]) j++;
            if(j < n) {cout<<a[j]-pre_sum<<endl;pre_sum += a[j]-pre_sum;j++;}
            else cout<<"0"<<endl;
        } else{
            cout<<"0"<<endl;
        }
    }
    return 0;
}
