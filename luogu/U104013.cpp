#include<bits/stdc++.h>

using namespace std;

long long mod = 1ll << 32;
int main()
{
    int a, b;
    cin >> a >> b;
    string s1, s2;
    cin >> s1 >> s2;
    long long ans = 0;
    for(int i = 0; i < s1.size(); i++)
    {
        int l = i-1, r = i+1;
        long long tmp = 0;
        if(s2.size()==1&&s1[i]==s2[0]) tmp++;
        while(l>=0&&r<=s1.size()-1)
        {
            if(s1[l]!=s1[r]) break;
            if(r-l+1>=s2.size())
            {
                if(s1[l]==s2[0])
                {
                    if(s1.substr(l, s2.size())==s2){tmp++;tmp%=mod;}
                }
                if(s1[r]==s2[s2.size()-1])
                {
                    if(s1.substr(r-s2.size()+1, s2.size())==s2){tmp++;tmp%=mod;}
                }
                if(r-l+1==s2.size() && s1.substr(l, s2.size())==s2){tmp--;}
            }
            ans += tmp;
            ans %= mod;
            l--;r++;
        }
    }
    cout << ans << endl;
    return 0;
}