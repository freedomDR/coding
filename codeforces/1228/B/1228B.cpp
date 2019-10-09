#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main()
{
    int h, w;
    cin >> h >> w;
    vector<int> hs(h), ws(w);
    vector<vector<bool>> white(h, vector<bool>(w)), black(h, vector<bool>(w));
    for(int i = 0; i < h; i++) cin >> hs[i];
    for(int i = 0; i < w; i++) cin >> ws[i];
    bool ok = true;
    for(int i = 0; i < h && ok; i++)
    {
        for(int k = 0; k < hs[i]; k++)
        {
            if(white[i][k]){ok=false;break;}
            black[i][k] = true;
        }
        if(hs[i] < w) white[i][hs[i]] = true;
    }
    for(int i = 0; i < w && ok; i++)
    {
        for(int k = 0; k < ws[i]; k++)
        {
            if(white[k][i]){ok=false;break;}
            black[k][i] = true;
        }
        if(ws[i] < h)
        {
            if(black[ws[i]][i] == true) {ok = false; break;}
            white[ws[i]][i] = true;
        }
    }
    if(!ok) {cout << "0" << endl;return 0;}
    long long ans = 1;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(!white[i][j]&&!black[i][j])
            {
                ans *= 2, ans %= MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
