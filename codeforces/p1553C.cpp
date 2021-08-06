#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int ans = 10;
        for(int i = 0; i < (1<<10); i++)
        {
            string ss;
            for(int j = 0, jj = i; j < 10; j++, jj /= 2)
                ss.push_back('0'+(jj%2));
            bool f = true;
            for(int j = 0; f && j < 10; j++)
                if(s[j] != '?' and ss[j]!=s[j])
                    f = false;
            if(!f)
                continue;
            int c1 = 0, c2 = 0, cc1 = 0, cc2 = 0;
            for(int j = 0; j < 10; j++)
                if(j%2==0)
                    cc1 += ss[j]-'0';
                else
                    cc2 += ss[j]-'0';
            for(int j = 0; j < 10 && j+1 < ans; j++)
            {
                if(ss[j]=='1' && j%2==0)
                    c1++;
                if(ss[j]=='1' && j%2==1)
                    c2++;
                if(c1 < c2 && cc1<=cc2)
                {
                    cout << ss << endl;
                    ans = min(j+1, ans);
                }
                if(c1 > c2 && cc1 >= cc2)
                {
                    cout << ss << endl;
                    ans = min(j+1, ans);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}