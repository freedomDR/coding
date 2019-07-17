#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ans[101][101], mid;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mid);
            ans[j][i] = mid;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
