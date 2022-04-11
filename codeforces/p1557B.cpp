#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]] = i;
        }
        sort(a.begin(), a.end());
        int pre = -2, need = 0;
        for(int i = 0; i < n; i++)
        {
            if(pre+1 != mp[a[i]])
            {
                need += 1;
            }
            pre = mp[a[i]];
        }
        if(need > k)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}