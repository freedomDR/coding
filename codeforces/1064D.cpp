#include <bits/stdc++.h>

using namespace std;
struct Node {
    int x, y, l, r;
};
char v[2010][2010];
int n, m, r, c, x, y, ans, xx[4] = {-1, 1, 0, 0}, yy[4] = {0, 0, -1, 1}, f[2010][2010];
int main()
{
    scanf("%d %d %d %d %d %d", &n, &m, &r, &c, &x, &y);
    for(int i = 1; i <= n; i++) scanf("%s", v[i]+1);
    deque<Node> q; q.push_back((Node){ r, c, x, y });
    while(!q.empty()){
        Node p; p = q.front(); q.pop_front();
        if(f[p.x][p.y] || (p.l < 0) || (p.r < 0)) continue;
        f[p.x][p.y] = 1; ans++;
        for(int i = 0; i < 4; i++){
            int tx = p.x+ xx[i], ty = p.y+yy[i];
            if(tx < 1 || tx > n || ty < 1 || ty > m || v[tx][ty] == '*' || f[tx][ty]) continue;
            if(i == 0 || i == 1) {q.push_front((Node){tx, ty, p.l, p.r}); continue;}
            if(i == 2) {q.push_back((Node){tx, ty, p.l-1, p.r});continue;}
            if(i == 3) {q.push_back((Node){tx, ty, p.l, p.r-1});continue;}
        }
    }
    printf("%d\n", ans);
    return 0;
}
