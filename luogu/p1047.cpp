#include <bits/stdc++.h>

using namespace std;

int tree[10100];

int main()
{
    int l, m;
    cin>>l>>m;
    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin>>l>>r;
        tree[l]++;
        tree[r+1]--;
    }
    int ans = 0, cnt = 0;
    for(int i = 0; i <= l; i++)
    {
        cnt+=tree[i];
        if(cnt == 0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
