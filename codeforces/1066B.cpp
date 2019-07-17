#include <bits/stdc++.h>

using namespace std;
int a[1050], b[1050];
int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[i] = b[i-1]+a[i];
    }
    int ans = 0, l = 0;
    while(l < n){
        int fla = 0;
        for(int i = min(n, l+r); i > max(0, l-r+1); i--){
            if(a[i]) {ans++; fla=1; l=i+r-1;break;}
        }
        if(!fla){
            ans = -1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
