#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q; cin >> q;
    while(q--)
    {
        int n; cin >> n;
        vector<int> in(n), out(n);
        for(auto &v:in) cin >> v;
        for(auto &v:out) cin >> v;
        stack<int> s;
        int i = 0, j = 0;
        while(true)
        {
            if(i<n) s.push(in[i++]);
            while(!s.empty() && j<n &&s.top()==out[j]) {s.pop();j++;}
            if(i==n) break;
        }
        cout << ((j==n)?"Yes":"No") << endl;
    }
    return 0;
}
