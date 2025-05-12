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
        ll tmp = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) s.insert(grid[i][j]);
            tmp += r[i];
            // cout << "row: " << i << " tmp: " << tmp << " sums: " << sums << endl;
            if (tmp == sums-tmp) return true;
            if (tmp>sums-tmp) {
                ll target = tmp-(sums-tmp);
                if (i==0&&(grid[i][0]==target||grid[i][m-1]==target)) return true;
                if (i>0&&m==1&&(grid[0][0]==target||grid[i][0]==target)) return true;
                if (i>0&&m>1&&s.contains(target)) return true; 
            }
        }

        s.clear();
        tmp = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < m; j++) s.insert(grid[i][j]);
            tmp += r[i];
            // cout << "row: " << i << " tmp: " << tmp << " sums: " << sums << endl;
            if (tmp == sums-tmp) return true;
            if (tmp>sums-tmp) {
                ll target = tmp-(sums-tmp);
                if (i==n-1&&(grid[i][0]==target||grid[i][m-1]==target)) return true;
                if (i<n-1&&m==1&&(grid[n-1][0]==target||grid[i][0]==target)) return true;
                if (i<n-1&&m>1&&s.contains(target)) return true; 
            }
        }

        s.clear();
        tmp = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) s.insert(grid[j][i]);
            tmp += c[i];
            // cout << "col: " << i << " tmp: " << tmp << " sums: " << sums << endl;
            if (tmp == sums-tmp) return true;
            if (tmp>sums-tmp) {
                ll target = tmp-(sums-tmp);
                if (i==0&&(grid[0][i]==target||grid[n-1][i]==target)) return true;
                if (i>0&&n==1&&(target==grid[0][i]||target==grid[0][0])) return true;
                if (i>0&&n>1&&s.contains(target)) return true;
            }
        }

        s.clear();
        tmp = 0;
        for (int i = m-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) s.insert(grid[j][i]);
            tmp += c[i];
            // cout << "col: " << i << " tmp: " << tmp << " sums: " << sums << endl;
            if (tmp == sums-tmp) return true;
            if (tmp>sums-tmp) {
                ll target = tmp-(sums-tmp);
                if (i==m-1&&(grid[0][i]==target||grid[n-1][i]==target)) return true;
                if (i<m-1&&n==1&&(target==grid[0][m-1]||target==grid[0][i])) return true;
                if (i<m-1&&n>1&&s.contains(target)) return true;
            }
        }
        return false;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> g = {};

    cout << s.canPartitionGrid(g) << endl;
    return 0;
}