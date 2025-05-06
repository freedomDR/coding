#include <bits/stdc++.h>
#include <algorithm>
#include <ios>
#include <ostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int sums = 0, max_v = INT_MIN, min_v = INT_MAX;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int v; cin >> v;
            sums += v;
            cnt[v]++;
            max_v = max(max_v, v);
            min_v = min(min_v, v);
        }
        if (max_v-min_v-1>k)
            cout << "Jerry" << endl;
        else if (max_v-min_v-1==k&&cnt[max_v]>1)
            cout << "Jerry" << endl;
        else if (sums%2)
            cout << "Tom" << endl;
        else  
            cout << "Jerry" << endl;
    }
    return 0;
}