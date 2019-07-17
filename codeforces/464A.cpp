#include <bits/stdc++.h>

using namespace std;
int n[5010];
int main()
{
    int num;
    scanf("%d",&num);
    for(int i = 1; i <= num; i++)
        scanf("%d", n+i);
    for(int i = 1; i <= num; i++){
        if(i == n[n[n[i]]]){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
