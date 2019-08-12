#include<bits/stdc++.h>
using namespace std;
const int N  = 20;
double x[N], y[N];
bool visit[N];
double dist[N][N];
int n;
double ans = DBL_MAX;

void dfs(int pass, int now, double v){
    if(v > ans) return;
    if(pass == n) {
        ans = min(ans, v);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!visit[i]) {
            visit[i] = true;
            dfs(pass+1, i, v+dist[now][i]);
            visit[i] = false;
        }
    }
};
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for(int i = 0; i <= n; i++) 
        for(int j = 0; j <= n; j++) 
            dist[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    dfs(0, 0, 0.0);
    printf("%.2f\n", ans);
    return 0;
}
