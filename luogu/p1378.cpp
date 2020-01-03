#include<bits/stdc++.h>
using namespace std;

int n;
double xx;
double yy;
double xxx;
double yyy;
const double PI = 3.1415926535;
double x[10], y[10];
double ans, maxv, r[10];
bool used[10];

double calc(int i)
{
    double d1 = min(abs(x[i]-xxx), abs(x[i]-xx));
    double d2 = min(abs(y[i]-yyy), abs(y[i]-yy));
    double d = min(d1, d2);
    for(int j = 0; j < n; j++)
    {
        if(j == i || !used[j]) continue;
        double temp = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        d = min(d, max(temp-r[j], 0.0));
    }
    return d;
}

void dfs(int k, double sums)
{
    if(k > n)
    {
        maxv = max(sums, maxv);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            r[i] = calc(i);
            used[i] = true;
            dfs(k+1, sums+PI*r[i]*r[i]);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    cin >> xx >> yy >> xxx >> yyy;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    maxv = 0;
    dfs(1, 0);
    cout << int(abs(xxx-xx)*abs(yyy-yy)-maxv+0.5) << endl;
    return 0;
}
