#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int> s;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool ans = false;
        s.clear();
        while(n--)
        {
            int v;

            cin >> v;
            s[v]++;
            if(v == 2048)
                ans = true;
            while(s[v] == 2)
            {
                s[v+v]++;
                s[v] = 0;
                v += v;
                if(v == 2048)
                    ans = true;
            }
        }
        cout << (ans?"YES":"NO") << endl;
    }
    return 0;
}
