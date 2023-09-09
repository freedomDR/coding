#include<bits/stdc++.h>

using namespace std;

void slove()
{
    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int l = 0, r = n-1;
    while(l < r && a[l]==1) l++;
    while(l < r && a[r]==1) r--;
    long long v = 1;
    for(int i = l; i <= r; i++)
    {
        v *= a[i];
        if(v > 1e9)
        {
            std::cout << l+1 << " " << r+1 << std::endl;
            return;
        }
    }
    std::vector<int> p;
    for(int i = l; i <= r; i++)
        if(a[i] > 1)
            p.push_back(i);
    int sums = std::accumulate(a.begin(), a.end(), 0);
    int L = 1, R = 1, ans = sums;
    for(int i = 0; i < p.size(); i++)
    {
        int l = p[i];
        int res = 1;
        int s = 0;
        for(int j = i; j < p.size(); j++)
        {
            int r = p[j];
            res *= a[r];
            s += a[r]-1;
            int v = sums-(r-l+1)-s+res;
            if(v > ans)
            {
                ans = v;
                L = l+1; R = r+1;
            }
        }
    }
    std::cout << L << " " << R << std::endl;
}

int main()
{
    int t; std::cin >> t;
    while(t--)
    {
        slove();
    }
    return 0;
}
