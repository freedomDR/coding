#include<bits/stdc++.h>

using namespace std;

struct T
{
    int c;
    int p;
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<T> c(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i].c = i-a[i];
        c[i].p = i;
    }
    sort(c.begin(), c.end(), [](T c1, T c2){return c1.c<c2.c;});
    long long ans = 0, tmp = 0;
    for(int i = 0, f = c[0].c; i < n; i++)
    {
        if(f==c[i].c)
        {
            tmp += a[c[i].p];
            continue;
        }
        ans = max(ans, tmp);
        tmp = 0;
        tmp += a[c[i].p];
        f = c[i].c;
    }
    ans = max(ans, tmp);
    cout << ans << endl;
}