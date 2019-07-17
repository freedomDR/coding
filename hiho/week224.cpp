#include <bits/stdc++.h>

using namespace std;
int a[200000];
int main()
{
    int t, A, k;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        memset(a, 0, sizeof(a));
        scanf("%d %d", &A, &k);
        for(int j = 0; j < A; j++){
            int tmp;
            scanf("%d", &tmp);
            a[tmp]++;
        }
        int ans = 1;
        for(int j = 0; j < A; j++){
            if(a[j] != 0){
                int tmp = a[j];
                for(int l = j; l < j+k; l++){
                    if(a[l] >= tmp){a[l] -= tmp;}
                    else{ans = 0; break;}
                }
            }
            if(!ans) break;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
