#include <bits/stdc++.h>

using namespace std;
int n, v[100010], t[100010];
muliset<long long> res;

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++) cin>>v[i];
    for(int i = 0; i < n; i++) cin>>t[i];
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        res.insert(v[i]+cnt);
        cnt+=t[i];
        long long ans = 0;
        while(!res.empty()&&(*res.begin()<=cnt)){
            ans+=(*res.begin()-cnt+t[i]);
            res.erase(res.begin());
        }
        ans+=res.size()*t[i];
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}
