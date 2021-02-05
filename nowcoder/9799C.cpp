#include<iostream>
#include<cmath>

using namespace std;

int a[1000010], f[1000010][20], prefix[1000010];
int n,q,s,w;

void ST()
{
    int tmp = log2(n);
    for(int i = 1; i <= n; i++)
        f[i][0] = a[i]^s;
    for(int j = 1; j <= tmp; j++)
        for(int i = 1; i+(1<<j)-1 <= n; i++)
            f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
}

int query(int l, int r)
{
    int s = log2(r-l+1);
    return max(f[l][s], f[r-(1<<s)+1][s]);
}

int main()
{
    cin >> n >> q >> s >> w;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i-1]^a[i];
    }
    ST();
    while(q--)
    {
        int l, r; cin >> l >> r;
        int ret = prefix[r]^prefix[l-1]^query(l, r)^s;
        int ans = 0;
        for(int i = 30; i >= 0; i--)
        {
            if((ans|(1<<i)) > w)
                continue;
            if(ret & (1<<i))
                continue;
            ans |= (1<<i);
        }
        cout << (ans|ret) << endl;
    }
}