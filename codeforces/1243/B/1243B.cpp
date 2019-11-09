#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k; cin >> k;
    while(k--)
    {
        int n; string s, t;
        cin >> n >> s >> t;
        bool ok = true;
        map<pair<char, char>, int> q;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == t[i]) continue;
            q[make_pair(s[i], t[i])]++;
        }
        int needs = 0;
        for(auto it:q)
        {
            needs += it.second/2;
            if(it.second%2 == 1) ok = false;
        }
        cout << (ok&&needs==1?"Yes":"No") << endl;
    }
    return 0;
}
