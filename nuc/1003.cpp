#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans;
    float c;
    do{
        scanf("%f",&c);
        if(c == 0.0) break;
        if(c <= 0.5){
            ans = 1;
        } else{
            ans = 1;
            c -= 0.5;
            while(c > 0){
                    ans++;
                c -= (1.0/(ans+1));
            }
        }
        printf("%d card(s)\n", ans);

    }while(1);
    return 0;
}
