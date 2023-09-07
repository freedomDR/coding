#include<bits/stdc++.h>

using namespace std;

int find_t(int x)
{
    for(int i = 2; i*i <= x; i++)
    {
        if(x%i==0) return i;
    }
    return 1;
}

int main()
{
    int t; cin >> t;
    int l, r;
    while(t--)
    {
        cin >> l >> r;
        if(r <= 3) cout << "-1" << endl;
        else if(l==r && r%2==1)
        {
            int v = find_t(r);
            if(v == 1)
                cout << "-1" << endl;
            else
                cout << v << " " << r-v << endl;
        }
        else cout << r/2 << " " << r/2 << endl;
    }
    return 0;
}
