#include <bits/stdc++.h>
#include <fmt/core.h>
#include <fmt/ranges.h>

using namespace std;

vector<int> slove(vector<int>& arr)
{
    int n = arr.size();
    vector<int> pos(n), ans(n);
    for(size_t i = 0; i < n; i++)
        pos[i] = i;
    sort(pos.begin(), pos.end(), [&arr](int l, int r) {return arr[l] < arr[r];});
    for(int i = 0; i < n; i++)
    {
        if(i == 0) 
        {
            ans[pos[i]] = 1;
            continue;
        }
        if(arr[pos[i]] == arr[pos[i-1]]) ans[pos[i]] = ans[pos[i-1]];
        else ans[pos[i]] = ans[pos[i-1]] + 1;
        
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto & v:arr)
        cin >> v;
    vector<int> ret = slove(arr);
    fmt::print("{}\n", ret);
    /* for(auto & v:ret) */
    /*     cout << v << endl; */
    return 0;
}
