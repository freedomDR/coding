#include <bits/stdc++.h>
#define N 300010
using namespace std;

vector<int> edge[N];
int f[N][26], n , m, d[N];
char s[N];
queue<int> Q;
int main()
{
    cin>>n>>m;
    scanf("%s",s+1);
    for(int i = 1; i <= m; i++){
        int x, y;
        cin>>x>>y;
        edge[x].push_back(y);
        d[y]++;
    }
    for(int i = 1; i <= n ;i++){
        if(!d[i]){
            Q.push(i);
            f[i][s[i] - 'a'] = 1;
        }
    }
    int rem = n;
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        rem--;
        for(int i = 0; i < edge[now].size(); i++){
            int to = edge[now][i];
            for(int j = 0; j < 26; j++){
                f[to][j] = max(f[to][j], f[now][j] + (s[to] - 'a' == j));
            }
            d[to]--;
            if(!d[to]) Q.push(to);
        }
    }
    if(rem) return puts("-1"), 0;
    int ans = 0;
    for(int i = 1; i <= n ;i++){
        for(int j = 0; j < 26; j++){
            ans = max(ans, f[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
