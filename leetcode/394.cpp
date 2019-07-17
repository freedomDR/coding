#include <bits/stdc++.h>

using namespace std;
string ans = "";
string decodeString(string s, int l = 0, int r = 0) {
    if(r == 0) r = s.size()-1;
    cout<<l<<" "<<r<<endl;
    while(l <= r)
    {
        if(s[l] >= 'a' && s[l] <= 'z') ans += s[l++];
        else if(s[l] >= '0' && s[l] <= '9')
        {
            int v = s[l++] - '0';
            while(l <= r && s[l] >= '0' && s[l] <= '9') v = v*10 + (s[l++]-'0');
            int ll = ++l, f = 1;
            while(f != 0)
            {
                if(s[l] == '[') f++;
                if(s[l] == ']') f--;
                l++;
            }
            cout<<l<<endl;
            if(ll != l-1) 
            {
                while(v--) decodeString(s, ll, l-2);
            }
        }
    }
    return ans;
}
int main()
{
    string s = "";
    cin>>s;
    cout<<decodeString(s)<<endl;
    return 0;
}
