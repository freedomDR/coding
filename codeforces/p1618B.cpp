#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string ans = "#";
        for(int i = 0; i < n-2; i++)
        {
            string c; cin >> c;
            if(c[0] != ans.back()) ans.push_back(c[0]);
            ans.push_back(c[1]);
        }
        for(int i = ans.size()-1; i < n; i++)
            ans.push_back('a');
        cout << ans.substr(1) << endl;
    }
    return 0;
}
