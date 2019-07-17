#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;
    int t, L, v, l, r;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d %d %d", &L, &v, &l, &r);
        ans = 0;
        ans = (int)(L/v) + (int)((l-1)/v) - (int)(r/v);
        printf("%d\n", ans);
    }
    return 0;
}
