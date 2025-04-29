#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    while(t--) {
        int n, m; cin >> n >> m;
        vector<string> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<int> row_one(n), col_one(m);
        int ones = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == '1') {
                    row_one[i]++;
                    col_one[j]++;
                    ones++;
                }
            }
        }
        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool f = true;
                for (int k = 0; k < 4; k++) {
                    int nx = i+dx[k], ny = j+dy[k];
                    if (nx<0||nx>=n||ny<0||ny>=m) continue;j
                    if (arr[nx][ny]=='0') { f = false; }
                }
                if (f) {
                    if (row_one[i]==m-1&&col_one[j]==n-1&&ones==m+n-2)  {
                        ok = true;
                        break;
                    }
                }
            }
        }

        int ro = 0, co = 0;
        for (auto & v:row_one) ro += (v==m);
        for (auto & v:col_one) co += (v==n);
        //cout << ro << " " << co << " " << ones << endl;
        if ((ro==2&&ones==m*2)||(co==2&&ones==n*2)||ones==0||ok) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}