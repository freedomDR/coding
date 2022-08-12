#include <bits/stdc++.h>
#include <fmt/core.h>
#include <fmt/ranges.h>

using namespace std;

vector<vector<int>> slove(vector<int>& arr)
{
    vector<vector<int>> ans;
    map<int, vector<int>> mp;
    for (int i = 0; i < arr.size(); i++) {
        if(mp.count(arr[i]) == 0) mp[arr[i]] = vector<int>();
        mp[arr[i]].push_back(i);
    }
    fmt::print("{}\n", mp);
    for(auto & v:mp)
    {
        int sz = v.first;
        vector<int> tmp;
        for(auto & vv:v.second)
        {
            tmp.push_back(vv);
            if(tmp.size() == sz)
            {
                ans.push_back(tmp);
                tmp.clear();
            }
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;
    vector<int> arr(n);
    for (auto& v : arr) {
        std::cin >> v;
    }
    fmt::print("{}\n", arr);
    auto ret = slove(arr);
    fmt::print("{}\n", ret);
    
    return 0;
}
