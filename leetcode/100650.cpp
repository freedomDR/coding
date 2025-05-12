#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll sums = 0;
        int n = grid.size(), m = grid[0].size();
        vector<ll> r(n), c(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sums += grid[i][j];
                r[i] += grid[i][j];
                c[j] += grid[i][j];
            }
        }
        if (sums%2) return false;
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += r[i];
            // cout << "row: " << i << " tmp: " << tmp << " sums: " << sums << endl;
            if (tmp == sums/2) return true;
        }
        tmp = 0;
        for (int i = 0; i < m; i++) {
            tmp += c[i];
            // cout << "col: " << i << " tmp: " << tmp << " sums: " << sums << endl;
            if (tmp == sums/2) return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> g = {{1,4},{2,3}};
    cout << s.canPartitionGrid(g) << endl;
    g = {{1,3},{2,4}};
    cout << s.canPartitionGrid(g) << endl;
    return 0;
}