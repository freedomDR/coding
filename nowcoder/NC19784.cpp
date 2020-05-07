
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        vector<int> a1, a2;
        double ans = 0;
        for(int i = 0; i < n; i++)
        {
            int a, b; cin >> a >> b;
            if(b==0) a1.push_back(a);
            else a2.push_back(a);
            ans += a;
        }
        sort(a1.begin(), a1.end());
        reverse(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        reverse(a2.begin(), a2.end());
        for(int i = 0, i1 = 0, i2 = 0; i < min(m, (int)a2.size()); i++)
        {
            if(i2 >= (int)a2.size()) break;
            if(i1 >= (int)a1.size()) {ans-=a2[i2++]/2.0;}
            else
            {
                if(a1[i1]>a2[i2]) ans-=a1[i1++]/2.0;
                else ans -= a2[i2++]/2.0;
            }
        }
        printf("%0.1f\n", ans);
    }
    return 0;
}