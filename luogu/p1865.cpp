#include<bits/stdc++.h>
using namespace std;

bool prime[1000001];
int ans[1000001], n, m;
int main()
{
    cin >> n >> m;
    prime[1] = true;
    for(int i = 2; i <= m; i++)
    {
        if(!prime[i])
        {
            ans[i] = ans[i-1]+1;
            for(int j = i+i; j <= m; j+=i)
                prime[j] = true;
        }
        else
            ans[i] = ans[i-1];
    }
    while(n--)
    {
        int l, r;
        cin >> l >> r;
        if(l < 1 || r > m) cout << "Crossing the line" << endl;
        else cout << (ans[r]-ans[l-1]) << endl;
    }
    return 0;
}
