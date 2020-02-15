#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> person(n);
    for(auto &it:person) cin >> it;
    unordered_map<string, int> cnt;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int money, num;
        cin >> money >> num;
        if(num == 0)
        {
            cnt[s] += money;
            continue;
        }
        for(int j = 0; j < num; j++)
        {
            string ss; cin >> ss;
            cnt[ss] += money/num;
        }
        cnt[s] += money%num;
        cnt[s] -= money;
    }
    for(int i = 0; i < n; i++)
    {
        cout << person[i] << " " << cnt[person[i]] << endl;
    }
    return 0;
}
