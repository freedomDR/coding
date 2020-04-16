#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, ans = 0;
        cin >> n;
        vector<vector<int>> pre(201, vector<int>(n+1));
        vector<int> a(n+1);
        for(int i = 1; i < n+1; i++)
        {
            cin >> a[i];
            for(int j = 1; j < 201; j++)
                pre[j][i] = pre[j][i-1];
            pre[a[i]][i]++;
            ans = max(ans, pre[a[i]][i]);
        }
        for(int x = 1; x <= 201; x++)
        {
            int l = 1, r = n, ls = 0, rs = 0;
            while(l<r)
            {
                while(l<r&&a[l]!=x) l++;
                if(l==r) break;
                while(l<r&&a[r]!=x) r--;
                if(l==r) break;
                ls++;rs++;
                int tmp = 0;
                for(int i = 1; i < 201; i++)
                {
                    tmp = max(tmp, pre[i][r-1]-pre[i][l]);
                }
                ans = max(ans, tmp+ls+rs);
                l++;r--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}