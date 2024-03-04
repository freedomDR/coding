#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>

using namespace std;

auto slove(std::vector<int> arr)
{
    auto time_1 = std::chrono::high_resolution_clock::now();
    std::vector<int> ans;
    std::vector<int> l, ll;
    std::vector<int> r, rr;
    l.push_back(arr[0]);
    ll.push_back(arr[0]);
    r.push_back(arr[1]);
    rr.push_back(arr[1]);
    for(int i = 2; i < arr.size(); i++)
    {
        auto d1 = std::distance(std::upper_bound(ll.begin(), ll.end(), arr[i]), arr.end());
        auto d2 = std::distance(std::upper_bound(rr.begin(), rr.end(), arr[i]), arr.end());
        if(d1 < d2)
        {
            r.push_back(arr[i]);
            rr.insert(std::upper_bound(rr.begin(), rr.end(), arr[i]), arr[i]);
        }
        if(d1 > d2)
        {
            l.push_back(arr[i]);
            ll.insert(std::upper_bound(ll.begin(), ll.end(), arr[i]), arr[i]);
        }
        if(d1 == d2 && l.size() <= r.size())
        {
            l.push_back(arr[i]);
            ll.insert(std::upper_bound(ll.begin(), ll.end(), arr[i]), arr[i]);
        }
        if(d1 == d2 && l.size() > r.size())
        {
            r.push_back(arr[i]);
            rr.insert(std::upper_bound(rr.begin(), rr.end(), arr[i]), arr[i]);
        }
    }
    ans.assign(l.begin(), l.end());
    ans.insert(ans.end(), r.begin(), r.end());
    auto time_2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> cost = time_2-time_1;
    std::cout << "cost " << cost.count() << "ms\n";
}

int main()
{
    return 0;
}