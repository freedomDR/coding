#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int m, n;
    cin >> m >> n;
    int p[200];
    for(int i = 0; i < m; i++) p[i] = 1;
    for(int i = 0, st = 0; i < m; i++) {
        for(int j = 0; j < n-1; j++) {
            ++st;
            if(st == m) st = 0;
            if(p[st] == 0) j--;
        }
        cout << st+1 << " ";
        p[st] = 0;
    }
    return 0;
}
