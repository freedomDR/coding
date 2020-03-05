#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; 
        string s;
        cin >> n >> s;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            bool ok = false;
            int p1 = i, p2 = ans, add1 = 1, add2 = 1;
            for(int j = 0; j < n; j++)
            {
                if(s[p1] < s[p2]) {ok = true;break;}
                else if(s[p1] > s[p2]) {break;}
                p1+=add1; p2+=add2;
                if(p1 == n)
                {
                    if((n-i)%2==0) p1 = 0;
                    else {p1 = i-1; add1 = -1;}
                }
                if(p2 == n)
                {
                    if((n-ans)%2==0) p2 = 0;
                    else {p2 = ans-1; add2 = -1;}
                }
            }
            if(ok) ans = i;
        }
        int add = 1;
        for(int i = 0, j = ans; i < n; i++)
        {
            cout << s[j];
            j+=add;
            if(j == n)
            {
                if((n-ans)%2==0) j = 0;
                else {j = ans-1;add=-1;}
            }
        }
        cout << endl << ans+1 << endl;
    }
    return 0;
}