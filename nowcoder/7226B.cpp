#include<iostream>
#include<set>
#include<map>
#include<vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = n;
    for(int i = 2; i <= n; i++)
    {
        map<int, int> mp;
        int tmp = 0;
        for(int j = 0; j < n; j++)
        {
            mp[a[j]]++;
            if(mp[a[j]] == 1) tmp++;
            if(j < i-1) continue;
            if(j == i-1)
            {
                ans += tmp;
                continue;
            }
            mp[a[j-i]]--;
            if(mp[a[j-i]] == 0) tmp--;
            ans += tmp;
        }
    }
    cout << ans << endl;
    return 0;
}