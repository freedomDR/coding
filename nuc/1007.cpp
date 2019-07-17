#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int tmp;
        scanf("%d", &tmp);
        char ans[10];
        int len = 0;
        while(tmp){
            ans[len] = (char)((int)'A'+((tmp-1)%26));
            len++;
            tmp = (tmp-1)/26;
        }
        for(int i = len-1; i >= 0; i--)
            printf("%c", ans[i]);
        printf("\n");
    }
    return 0;
}

