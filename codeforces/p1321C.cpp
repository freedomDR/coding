#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "0"+s+"0";
    int ans = 0;
    while(1)
    {
        int pos = -1;
        for(int i = 1; i <=n; i++)
        {
            if(s[i]==s[i+1]+1||s[i]==s[i-1]+1)
            {
                if(pos==-1||s[i]>s[pos])
                    pos = i;
            }
        }
        if(pos==-1) break;
        ans++;
        n--;
        s.erase(pos, 1);
    }
    cout << ans << endl;
    return 0;
}