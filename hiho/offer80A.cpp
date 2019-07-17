#include <bits/stdc++.h>

using namespace std;
#define MAX 100050
int n[MAX][25];
int main()
{
    int N;
    cin>>N;
    for(int i = 0; i < N; i++){
        int h, m, s, id;
        scanf("%d %d:%d:%d", &id, &h, &m, &s);
        if(m ==0 && s == 0){
            if(h == 0) n[id][0]++;
            else n[id][h-1]++;
        }else{
            n[id][h]++;
        }
    }
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < 25; j++){
            if(n[i][j] >= 1){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
