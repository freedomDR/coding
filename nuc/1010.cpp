#include <bits/stdc++.h>

using namespace std;
int n, x, y;
char m[81][81];
int mm[81][81];
int pathh[1001];
int ans;

void slove(int xx, int yy, int p){
    if(ans != 0)
        return;
    if(xx == n-1 && yy == n-1){
        ans = p;
        return;
    }
    if(xx == -1 || xx == n || yy == -1 || yy == n){
        return;
    }
    if(m[xx][yy] == '1'){
        return;
    }
    if(mm[xx][yy] == 1)
        return;
    mm[xx][yy] = 1;
    if(ans == 0){
        pathh[p] = 1;
        slove(xx+1,yy, p+1);
    }
    if(ans == 0){
        pathh[p] = 2;
        slove(xx-1,yy, p+1);
    }
    if(ans == 0){
        pathh[p] = 3;
        slove(xx,yy+1, p+1);
    }
    if(ans == 0){
        pathh[p] = 4;
        slove(xx,yy-1, p+1);
    }
}
int main()
{
    ans = 0;
    memset(mm, 0, sizeof(mm));
    cin>>n>>y>>x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>m[i][j];
        }
    }
    slove(--x,--y, 0);
    if(ans){
        cout<<"Found"<<endl;
        m[x][y] = '#';
        for(int i = 0; i < ans; i++){
            if(pathh[i] == 1)
                x++;
            else if(pathh[i] == 2)
                x--;
            else if(pathh[i] == 3)
                y++;
            else
                y--;
            m[x][y] = '#';
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}
