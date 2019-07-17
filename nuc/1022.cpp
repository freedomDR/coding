#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y, mid;
    while(scanf("%d %d %d", &n, &x, &y) != EOF){
        for(int i = 1; i <= n; i++){
            printf("(%d,%d)", x, i);
        }
        printf("\n");
        for(int i = 1; i <= n; i++){
            printf("(%d,%d)", i, y);
        }
        printf("\n");
        mid = min(x,y) - 1;
        for(int xx = x-mid, yy = y-mid; xx <= n && yy <= n; xx++, yy++){
            printf("(%d,%d)", xx, yy);
        }
        printf("\n");
        mid = min(n-x,y-1);
        for(int xx = x+mid, yy = y-mid; xx > 0 && yy <= n; xx--, yy++){
            printf("(%d,%d)", xx, yy);
        }
        printf("\n");
    }
    return 0;
}
