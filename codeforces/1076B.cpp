#include <bits/stdc++.h>

using namespace std;

long long min_prime(long long n){
    long long i = 2;
    while(i*i <= n){
        if(n%i == 0) return i;
        i++;
    }
    return n;
}

int main()
{
    long long n,ans = 0;
    cin>>n;
    if(n%2 != 0){
        n -= min_prime(n);
        ans++;
    }
    cout<<ans+(n/2)<<endl;
    return 0;
}
