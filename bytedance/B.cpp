#include<bits/stdc++.h>
using namespace std;
int a[1100], ans[1100], s[1100];
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        int suffix = 0;
        priority_queue<int> q;
        for(int i = 0; i < n; i++)
        {
            int jj = q.size()-1, temp = suffix;
            while(m-temp < a[i] && jj >= 0)
            {
                temp-=a[jj];
                jj--;
            }
            ans[i] = i-jj-1;
            q.push(a[i]);
            suffix += a[i];
            while(suffix > m)
            {
                suffix -= q.top();
                q.pop();
            }
        }
        for(int i = 0; i < n; i++) cout << ans[i] <<" ";
        cout << endl;
    }
    return 0;
}
