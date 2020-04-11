#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        bool ok = true;
        cin >> n;
        int p1 = 0, p2 = 0;
        for(int i = 0; i < n; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            int t1 = v1-p1, t2 = v2-p2;
            if(t1 < 0) ok = false;
            if(t2 < 0) ok = false;
            if(t2 > t1) ok = false;
            p1 = v1; p2 = v2;
        }
        cout << (ok?"YES":"NO") << endl;
    }
    return 0;
}