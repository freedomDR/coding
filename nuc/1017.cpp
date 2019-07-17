#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,r,l,day;
    char s[2][101][101];
    cin>>n;
    while(n--){
        cin>>r>>l>>day;
        memset(s, 0, sizeof(s));
        for(int i = 0; i < r; i++){
            scanf("%s", s[0][i]);
        }
        for(int i = 0; i < day; i++){
            int f = (i+1)%2, ff = i%2;
            bool equalb = true;
            for(int ii = 0; ii < r; ii++){
                for(int jj = 0; jj < l; jj++){
                    char mid = ' ';
                    if(s[ff][ii][jj] == 'P')
                        mid = 'S';
                    else if(s[ff][ii][jj] == 'S')
                        mid = 'R';
                    else
                        mid = 'P';
                    if((ii-1) >= 0 && s[ff][ii-1][jj] == mid){
                        s[f][ii][jj] = s[ff][ii-1][jj];
                        equalb = false;
                    }else if((ii+1) < r && s[ff][ii+1][jj] == mid){
                        s[f][ii][jj] = s[ff][ii+1][jj];
                        equalb = false;
                    }else if((jj-1) >= 0 && s[ff][ii][jj-1] == mid){
                        s[f][ii][jj] = s[ff][ii][jj-1];
                        equalb = false;
                    }else if((jj+1) < l && s[ff][ii][jj+1] == mid){
                        s[f][ii][jj] = s[ff][ii][jj+1];
                        equalb = false;
                    }else{
                        s[f][ii][jj] = s[ff][ii][jj];
                    }
                }
            }
            if(equalb)
                break;
        }
        for(int i = 0; i < r; i++){
            printf("%s", s[day%2][i]);
            printf("\n");
        }
        if(n != 0)printf("\n");
    }
    printf("0\n");
    return 0;
}
