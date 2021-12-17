#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s, t;
        cin >> s >> t;
        vector<int> cnt(30);
        for(auto &v:s) cnt[v-'a']++;
        if(t == "abc" && cnt[0] > 0)
        {
            for(int i = 0; i < cnt[0]; i++)
                cout << 'a';
            cnt[0] = 0;
            for(int i = 0; i < cnt[2]; i++)
                cout << 'c';
            cnt[2] = 0;
        }
        for(int i = 0; i < cnt.size(); i++)
        {
            for(int j = 0; j < cnt[i]; j++)
                cout << char(i+'a');
        }
        cout << endl;
    }
    return 0;
}
