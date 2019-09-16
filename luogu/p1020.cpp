#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v;
    vector<int> a;
    while((cin >> v)) a.emplace_back(v);
    vector<int> d1, d2;
    d1.push_back(INT_MAX);
    d2.push_back(INT_MIN);
    for(auto &it:a)
    {
        if(it <= d1.back()) d1.push_back(it);
        else d1[distance(d1.begin(), upper_bound(d1.begin(), d1.end(), it, greater<int>()))] = it;
        if(it > d2.back()) d2.push_back(it);
        else d2[distance(d2.begin(), lower_bound(d2.begin(), d2.end(), it))] = it;
    }
    cout << (d1.size()-1) << endl;
    cout << (d2.size()-1) << endl;
    return 0;
}
