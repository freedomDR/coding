#include <bits/stdc++.h>

using namespace std;
int r,c;
char s[510][510];

int main()
{
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cin>>s[i][j];
    }
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            if(s[i][j] == 'W'){
                if(i+1<r)
                    if(s[i+1][j] == 'S'){
                        printf("No\n");
                        return 0;
                    }else if(s[i+1][j] == '.'){
                        s[i+1][j] = 'D';
                    }
                if(i-1>=0)
                    if(s[i-1][j] == 'S'){
                        printf("No\n");
                        return 0;
                    }else if(s[i-1][j] == '.'){
                        s[i-1][j] = 'D';
                    }
                if(j+1<c)
                    if(s[i][j+1] == 'S'){
                        printf("No\n");
                        return 0;
                    }else if(s[i][j+1] == '.'){
                        s[i][j+1] = 'D';
                    }
                if(j-1>=0)
                    if(s[i][j-1] == 'S'){
                        printf("No\n");
                        return 0;
                    }else if(s[i][j-1] == '.'){
                        s[i][j-1] = 'D';
                    }
            }
        }
    printf("Yes\n");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}
