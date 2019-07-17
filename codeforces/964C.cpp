#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+9;
long long powd(int a, int b){
    long long ret = 1;
    a = a % MOD;
    while(b > 0){
        if(b&1)
            ret = ret * a % MOD;
        b = b / 2;
        a = (long long)a * a % MOD;
    }
    return ret;
}

int n, a, b, k;
char s[100010];
int main()
{
    cin>>n>>a>>b>>k;
    scanf("%s", s);
    long long ret = 0;
    for(int i = 0 ; i <= n; i++){
        int flag = 1;
        if(s[i%k] == '-') flag = -1;
        ret = (ret+flag*powd(a, n-i)%MOD*powd(b, i)%MOD)%MOD;
    }
    cout<<(ret+MOD)%MOD<<endl;
    return 0;
}
