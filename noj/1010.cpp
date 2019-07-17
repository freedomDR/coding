#include <bits/stdc++.h>

using namespace std;

int n, x, y, found = 0, f[85][85], x_add[] = {0, 0, 1, -1}, y_add[] = {1, -1, 0, 0};
char s[85][85];
vector<pair<int, int>> path, real_path;

void dfs(int xx, int yy){
    if(xx == n-1 && yy == n-1){
        found = 1;
        real_path.assign(path.begin(), path.end());
        return;
    }
    if(xx < 0 || xx == n || yy < 0 || yy == n) return;
    if(f[xx][yy] == 0) f[xx][yy] = 1;
    else return;
    if(s[xx][yy] == '1' || found == 1) return;
    for(int i = 0 ; i < 4; i++){
        path.push_back(make_pair(xx+x_add[i], yy+y_add[i]));dfs(xx+x_add[i], yy+y_add[i]);path.pop_back();
    }
}

int main()
{
    cin>>n>>y>>x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>s[i][j];
    x--;y--;
    path.push_back(make_pair(x,y));
    dfs(x, y);
    while(!real_path.empty()){
        pair<int, int> i = real_path.back();
        s[i.first][i.second] = '#';
        real_path.pop_back();
    }
    if(found == 1){
        cout<<"Found"<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ;j++)
                cout<<s[i][j]<<" ";
            if(i < n-1) cout<<endl;
        }
    }else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}
