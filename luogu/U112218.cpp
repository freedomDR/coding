#include<bits/stdc++.h>

using namespace std;
int a[10], mod = 10000;
int main()
{
    string s;
    cin >> s;
    for(int i = 1; i < 10; i++)
    {
        int l =  (i-1)*4, cnt = 0;
        for(int j = 0; l+i<=(int)s.size(); j++)
        {
            cnt = cnt*10+(s[l+i]-'0');
        }
        a[i] = cnt;
    }
    int add = 0;
    for(int i = 1; i < 10; i++)
    {
        double tmp = a[i]*1.5 + add;
        add = (int)tmp / mod;
        a[i] = (int)tmp % mod;
        a[i-1] += (int)(tmp-(int)tmp)*mod;
    }
    for(int i = 0; i+1 < 10; i++)
    {
        if(a[i] >= mod) {a[i+1] += a[i]/mod;a[i]%=mod;}
    }
    int p = 9;
    while(p>=0&&a[p] == 0) p--;
    string ans = "";
    for(int i = 9; i >= 0; i--)
    {
        if(i == 0) ans += ".";
        for(int j = 1, div=mod/10; j <= 5; j++, div /= 10)
            ans.push_back((a[i]/div)%10 + '0');
    }
    p = 0;
    while(ans[p] == '0') p++;
    if(p=='.') p--;
    for(int i = p; i < ans.size(); i++)
    {
        cout << ans[p];
    }
    cout << endl;
    return 0;
}