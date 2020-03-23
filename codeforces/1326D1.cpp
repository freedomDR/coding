#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s, ans = "";
        cin >> s;
        int same = 0;
        for(int ll = 0, rr = s.size()-1; ll < rr; ll++, rr--)
        {
            if(s[ll]==s[rr]) same++;
            else break;
        }
        for(int l = 0; l <= s.size(); l++)
        {
            for(int r = max(0, same*2-l); r+l <= s.size() && !(l>same&&r>same); r++)
            {
                if(r+l <= ans.size()) continue;
                int pos = s.size()-r;
                string tmp = s.substr(0, l) + s.substr(pos, r);
                bool ok = true;
                for(int i = 0, j = tmp.size()-1; i < j && ok; i++, j--)
                {
                    if(tmp[i] != tmp[j]) ok = false; 
                }
                if(ok) ans = tmp; 
            }
        }
        cout << ans << endl;
    }
    return 0;
}