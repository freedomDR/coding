#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<vector<int> > arr(n, vector<int>());
    for(int i = 0; i < n; i++)
    {
        int nums = 0; cin >> nums;
        for(int j = 0; j < nums; j++)
        {
            int v; cin >> v; arr[i].push_back(v);
        }
        sort(arr[i].begin(), arr[i].end());
    }
    int q; cin >> q;
    while(q--)
    {
        int l, r, k, p;
        cin >> l >> r >> k >> p;
        l--;r--;k--;
        int f = arr[k][arr[k].size()-p];
        int ans = 0;
        for(int i = l; i <= r; i++)
        {
            auto ret = upper_bound(arr[i].begin(), arr[i].end(), f);
            ans += distance(ret, arr[i].end());
        }
        cout << ans+1 << endl;
    }
    return 0;
}