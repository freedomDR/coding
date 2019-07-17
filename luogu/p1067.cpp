#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> t(n+1);
    for(int i = 0; i <= n; i++) cin>>t[i];
    for(int i = 0; i <= n; i++)
    {
        if(t[i] == 0) continue;
        if(i != 0 && t[i]>0) cout<<"+";
        if(t[i]<0) cout<<"-";
        if(abs(t[i]) == 1 && i != n){}
        else cout<<abs(t[i]);
        
        if(i == n) continue;
        else
        {
            cout<<"x";
            if(i != n-1) cout<<"^"<<(n-i);
        }
    }
    return 0;
}
