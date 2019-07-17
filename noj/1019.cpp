#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
int prime[N], sum[N], n, l, r;

int judge(int x){
    if(x < 4) return 0;
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0) return 1;
    }
    return 0;
}

int main()
{
    for(int i = 2; i < N; i++){
        if(prime[i] == 1) continue;
        prime[i] = judge(i);
        for(int j = i+i; j < N; j+=i)
            prime[j] = 1;
    }
    for(int i = 2; i < N; i++){
        sum[i] = sum[i-1]+(prime[i]^1);
    }
    cin>>n;
    while(n--){
        cin>>l>>r;
        cout<<(sum[r]-sum[l]+(prime[l]^1))<<endl;
    }
    cout<<"END"<<endl;
    return 0;
}
