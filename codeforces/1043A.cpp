#include <bits/stdc++.h>

using namespace std;
int a[105];
int main()
{
    int n;
    cin>>n;
    int ans = 0, maxx = 0, sum = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        maxx = max(maxx, tmp);
        sum += tmp;
    }
    ans = maxx;
    while(ans*n - sum <= sum){
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
