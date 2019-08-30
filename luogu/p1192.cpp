#include<bits/stdc++.h>
using namespace std;
const int mod = 100003;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N+1);
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(i < K+1) a[i] = 2*a[i-1]%mod;
        else a[i] = 2*a[i-1]-a[i-K-1], a[i] %= mod;
    }
    cout << (a[N]+mod)%mod <<endl;
    return 0;
}
