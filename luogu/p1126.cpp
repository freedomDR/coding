#include<bits/stdc++.h>

using namespace std;

struct node 
{
    int x, y, w, s;
}startN, endN, nowN, nextN;

int n, m;
int mx[55][55];
int ans = -1;
int vis[55][55][4];
int dx[] = {0, 0, -1, 1}; // 左右上下
int dy[] = {-1, 1, 0, 0};
int turnLeft[] = {3, 2, 0, 1};
int turnRight[] = {2, 3, 1, 0};
char C[] = {'W', 'E', 'N', 'S'};

void bfs() 
{
    queue<node> q;
    startN.s = 0;
    vis[startN.x][startN.y][startN.w] = 1;
    q.push(startN);
    while(!q.empty()) 
    {
        nowN = q.front(); q.pop();
        // cout << nowN.x << " " << nowN.y << " " << C[nowN.w] << " " << nowN.s << endl;
        if(nowN.x == endN.x && nowN.y == endN.y)
        {
            ans = nowN.s;
            return;
        }
        nextN = nowN;
        for(int i = 1; i < 4; i++)
        {
            nextN.x += dx[nextN.w], nextN.y += dy[nextN.w];
            if(nextN.x < 1 || nextN.x >= n || nextN.y < 1 || nextN.y >= m || mx[nextN.x][nextN.y])
                break;
            if(vis[nextN.x][nextN.y][nextN.w]) continue;
            vis[nextN.x][nextN.y][nextN.w] = 1;
            nextN.s = nowN.s + 1;
            q.push(nextN);
        }
        nextN = nowN;
        nextN.s = nowN.s + 1;
        nextN.w = turnLeft[nowN.w];
        if(!vis[nextN.x][nextN.y][nextN.w])
        {
            vis[nextN.x][nextN.y][nextN.w] = 1;
            q.push(nextN);
        }
        nextN.w = turnRight[nowN.w];
        if(!vis[nextN.x][nextN.y][nextN.w])
        {
            vis[nextN.x][nextN.y][nextN.w] = 1;
            q.push(nextN);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
        {
            cin >> mx[i][j];
            if(mx[i][j] == 1)
                mx[i][j] = mx[i-1][j] = mx[i][j-1] = mx[i-1][j-1] = 1;
        }    
    cin >> startN.x >> startN.y >> endN.x >> endN.y;
    char tmp; cin >> tmp;
    if(tmp == 'W')  startN.w = 0;
    if(tmp == 'E')  startN.w = 1;
    if(tmp == 'N')  startN.w = 2;
    if(tmp == 'S')  startN.w = 3;
    bfs();
    cout << ans << endl;
    return 0;
}