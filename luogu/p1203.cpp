#include<bits/stdc++.h>
using namespace std;
int n;
string a;

int find(int p)
{
    char l = a[p], r = a[p+1];
    int cnt = 0;
    for(int i = p;;i--)
    {
        if(a[i] == l) cnt++;
        else if(a[i] == 'w') cnt++;
        else break;
    }
    for(int i = p+1;;i++)
    {
        if(a[i] == r) cnt++;
        else if(a[i] == 'w') cnt++;
        else break;
    }
    return cnt;
}

int main()
{
    int ans = -1;
    cin >> n >> a;
    a = a+a+a;
    for(int i = n; i < 2*n; i++)
    {
        if(a[i] == a[i+1]) continue;
        if(a[i] == 'w')
        {
            a[i] = 'r';
            ans  = max(ans, find(i));
            a[i] = 'b';
            ans = max(ans, find(i));
            a[i] = 'w';
        }
        ans = max(ans, find(i));
    }
    ans = min(n, ans);
    if(ans == -1) ans = n;
    cout << ans << endl;
    return 0;
}
