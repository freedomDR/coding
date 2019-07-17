#include <bits/stdc++.h>

using namespace std;

int main()
{
    long t, a;
    scanf("%ld", &t);
    for(int i = 0; i < t; i++){
        scanf("%ld", &a);
        long ans = 0;
        while(a){
            if(a&1) ans++;
            a >>= 1;
        }
        printf("%ld\n", (long)1<<ans);
    }
    return 0;
}
