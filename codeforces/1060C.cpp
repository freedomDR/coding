#include <bits/stdc++.h>
using namespace std;
const int MAX=2050;
long long x[MAX], y[MAX], xs[MAX], ys[MAX];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, xx;
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>x[i];
    for(int i = 0; i < m; i++) cin>>y[i];
    cin>>xx;
    for(int i = 0; i < MAX; i++) xs[i]=ys[i]=xx+1;
    for(int i = 0; i < n; i++){
        long long sum = 0;
        for(int j = i; j < n; j++){
            sum += x[j];
            xs[j-i] = min(xs[j-i], sum);
        }
    }
    for(int i = 0; i < m; i++){
        long long sum = 0;
        for(int j = i; j < m; j++){
            sum += y[j];
            ys[j-i] = min(ys[j-i], sum);
        }
    }
    for(int i = 0; i < n && xs[i] != xx+1; i++){
        for(int j = 0; j < m && ys[j] != xx+1; j++){
            if(xs[i]*ys[j] <= xx) ans = max(ans, (i+1)*(j+1));
        }
    }
    cout<<ans<<endl;
    return 0;
}
