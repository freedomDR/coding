#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    long long ans[1000001];
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 1;
    for(int j = 3; j < 1000001; j++){
        ans[j] = ans[j-1]+ans[j-2];
        ans[j] %= int(1e7);
    }
    scanf("%d", &n);
    while(n--){
        scanf("%d",&i);
        printf("%lld\n",ans[i]);
    }
    return 0;
}
