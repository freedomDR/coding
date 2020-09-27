#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    string p = "puleyaknoi";
    cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int len = s.size();
        vector<vector<int>> pos(26, vector<int>());
        for(int i = 0; i < len; i++)
            pos[s[i]-'a'].push_back(i);
        int ans = 1e8;
        for(int i = 0; i < int(pos['p'-'a'].size()); i++)
        {
            int left = pos['p'-'a'][i];
            cout << left << " ";
            bool f = true;
            for(int j = 1; j < 10; j++)
            {
                cout << p[j] << " ";
                auto it = upper_bound(pos[p[j]-'a'].begin(), pos[p[j]-'a'].end(), left);
                if(it == pos[p[j]-'a'].end()) {f=false;break;}
                left = *it;
                cout << left << " ";
            }
            cout << endl;
            if(f) ans = min(ans, left-pos['p'-'a'][i]+1);
        }
        if(ans == 1e8) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}