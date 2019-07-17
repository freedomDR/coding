#include <bits/stdc++.h>

using namespace std;
int t[200500];

int main()
{
    int q, l, r, v;
    char s;
    l = 1; r = 0;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf(" %c %d", &s, &v);
        if(s == 'L'){
            t[v] = --l;
        }else if(s == 'R'){
            t[v] = ++r;
        }else{
            printf("%d\n", min(t[v] - l,r- t[v]));
        }
    }
    return 0;
}
