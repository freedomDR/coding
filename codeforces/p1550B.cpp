#include<iostream>
#include<string>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        int ans = a*n;
        if(b>=0)
            ans += b*n;
        else
        {
            int zero_cnt = 0, one_cnt = 0;
            int pos = 0;
            while(pos < n)
            {
                while(pos < n && s[pos]=='1') pos++;
                if(pos == n) break;
                zero_cnt++;
                while(pos < n && s[pos]=='0') pos++;
            }
            pos = 0;
            while(pos < n)
            {
                while(pos < n && s[pos]=='0') pos++;
                if(pos == n) break;
                one_cnt++;
                while(pos < n && s[pos]=='1') pos++;
            }
            if(zero_cnt == 0) ans += b;
            else if(one_cnt == 0) ans += b;
            else ans += min(zero_cnt+1, one_cnt+1)*b;
        }
        cout << ans << endl;
    }
    return 0;
}