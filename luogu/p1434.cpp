#include<bits/stdc++.h>
using namespace std;
int R, C;
const int dx[4]= {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int g[101][101], vi[101][101];

int dfs(int i, int j)
{
    if(vi[i][j]) return vi[i][j];
    int temp = 1;
    for(int z = 0; z < 4; z++) {
        int x = dx[z]+i, y = dy[z]+j;
        if(x == -1 || y == -1 || x == R || y == C || g[i][j] <= g[x][y]) continue;
        temp = max(temp, dfs(x, y)+1);
    }
    return vi[i][j]=temp;
}

//记忆化搜索
void slove1()
{
    int ans = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            vi[i][j] = dfs(i, j);
            ans = max(ans, vi[i][j]);
        }
    }
    cout << ans << endl;
}

typedef struct P{
    int x, y, v;
}point;

point p[10001];

//非递归
void slove2()
{
    int n = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            p[n].x = i; p[n].y = j; p[n].v = g[i][j];
            n++;
        }
    sort(p, p+(R*C), [](point p1, point p2) { return p1.v < p2.v;});
    vector<int> ans(R*C, 1);
    for(int i = 0; i < R*C; i++) {
        for(int j = 0; j < i; j++) {
            if(p[j].v >= p[i].v) break;
            bool isadj = false;
            for(int z = 0; z < 4; z++) {
                if(p[i].x+dx[z] == p[j].x && p[i].y+dy[z] == p[j].y) {isadj=true;break;}
            }
            if(isadj) ans[i] = max(ans[i], ans[j]+1);
        }
    }
    int res = 0;
    for(auto v:ans) {
        res = max(res, v);
    }
    cout << res << endl;

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> g[i][j];
        }
    }
    /* slove1(); */
    slove2();
    return 0;
}
