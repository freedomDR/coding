#include<bits/stdc++.h>

using namespace std;

struct T
{
    int y, x1, x2;
    bool operator < (const T &tt)
    {
        if(y==tt.y) return x1 < tt.x2;
        else return y < tt.y;
    }
}t[105];
int n, b[10005];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {cin >> t[i].y >> t[i].x1 >> t[i].x2; t[i].x2--;}
    sort(t+1, t+n+1);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += (t[i].y-b[t[i].x1] + t[i].y-b[t[i].x2]);
        for(int j = t[i].x1; j <= t[i].x2; j++)
        {
            b[j] = t[i].y;
        }
    }
    cout << ans << endl;
    return 0;
}