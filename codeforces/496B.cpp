#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a, b;
    int n, m, l, j, a_sum, b_sum, ans = 0;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>l;
        a.push_back(l);
    }
    for(int i = 0; i < m; i++){
        cin>>l;
        b.push_back(l);
    }
    for(l = 0, j = 0, a_sum = a[l], b_sum = b[j]; l < n && j < m;){
        if(a_sum == b_sum){
            a_sum = 0;b_sum = 0;
            l++;j++;
            ans++;
            a_sum += a[l];b_sum += b[j];
        }else if(a_sum < b_sum){
            l++;
            a_sum += a[l];
        }else{
            j++;
            b_sum += b[j];
        }
    }
    cout<<ans<<endl;
    return 0;
}
