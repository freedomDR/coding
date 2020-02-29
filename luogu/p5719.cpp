#include<bits/stdc++.h>
using namespace std;

int f[10001];
int n, k;
int main()
{
    cin >> n >> k;
    for(int i = k; i <= n; i+=k)
    {
        f[i] = 1;
    }
    int sums = 0, cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(f[i] == 1) sums += i, cnt++;
    }
    if(cnt == 0) printf("0.0 ");
    else printf("%0.1f ", sums*1.0/cnt);
    sums = 0; cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(f[i] == 0) sums += i, cnt++;
    }
    if(cnt == 0) printf("0.0 ");
    else printf("%0.1f ", sums*1.0/cnt);
    return 0;
}
