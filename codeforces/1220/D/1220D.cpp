#include<bits/stdc++.h>
using namespace std;
long long b[200010];
int main()
{
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b+n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
    return 0;
}
