#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;cin>>s;
        set<char> cnt;
        bool ok1 = false, ok2 = true;
        for(int i = 0; i < s.size(); i++){
            if(cnt.count(s[i])) ok2 = false;
            if(cnt.count(s[i]-1)) ok1 = true;
            if(cnt.count(s[i]+1)) ok1 = true;
            cnt.insert(s[i]);
        }
        
        if(ok1&&ok2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
