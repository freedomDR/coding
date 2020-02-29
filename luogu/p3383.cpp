#include<bits/stdc++.h>
using namespace std;

int n, q, isprime[100001000], prime[100100], tot;

int main()
{
    cin >> n >> q;
    isprime[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(isprime[i] == 0)
        {
            prime[++tot] = i;
        }
        for(int j = 1; j <= tot && i*j <= n; j++)
        {
            isprime[i*prime[j]] = 1;
            if(i%prime[j] == 0) break;
        }
    }
    while(q--)
    {
        int k; cin >> k;
        cout << prime[k] << endl;
    }
    return 0;
}
