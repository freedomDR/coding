#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr;
    set<int> b;
    b.insert(1);
    b.insert(2);
    arr.emplace_back(b.begin(), b.end());
    return 0;
}