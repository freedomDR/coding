#include <bits/stdc++.h>

using namespace std;

int dig[] = {1,1,2,6,4,2,2,4,2,8};
long long slove(long long t){
    if(t < 10) return dig[t];
    if((t/10)%10%2 == 0)
        return (6*slove(t/5)*dig[t%10])%10;
    else
        return (4*slove(t/5)*dig[t%10])%10;
}
int main()
{
    long long n, ans;
    while(cin>>n){
        cout<<slove(n)<<endl;
    }
    return 0;
}
