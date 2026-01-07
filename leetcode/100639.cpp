#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        vector<vector<pii>> e(26);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]>='A'&&matrix[i][j]<='Z')
                    e[matrix[i][j]-'A'].emplace_back(i, j);
            }
        }
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        dis[0][0] = 0;
        pq.emplace(0, 0, 0);
        while(!pq.empty()) {
            auto [cnt, x, y] = pq.top();
            if (x==n-1&&y==m-1) return cnt;
            pq.pop();
            if (cnt > dis[x][y]) continue;
            int c = matrix[x][y];
            if (c>='A'&&c<='Z') {
                for (pii p:e[c-'A']) {
                    if (dis[p.first][p.second]>cnt) {
                        dis[p.first][p.second] = cnt;
                        pq.emplace(cnt, p.first, p.second);
                    }
                }
                // # 可恶啊，忘记清理了
                e[c-'A'].clear();
            }
            for (int i = 0; i < 4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if (matrix[nx][ny]!='#'&&dis[nx][ny]>cnt+1) {
                    dis[nx][ny]=cnt+1;
                    pq.emplace(cnt+1, nx, ny);
                }
            }
        }
        return dis[n-1][m-1]==INT_MAX?-1:dis[n-1][m-1];
    }
};

int main()
{
    vector<string> arr = {"A..",".A.","..."};
    Solution s;
    cout << s.minMoves(arr) << endl;
    arr = {".#...",".#.#.",".#.#.","...#."};
    cout << s.minMoves(arr) << endl;
    arr = {"HH",".C"};
    cout << s.minMoves(arr) << endl;
    arr = {"..BC.C.","...F..G","#.F..FA","D.ABEAB","E....BE","ADDF...","E#..BA.","#FD#.#A"};
    cout << s.minMoves(arr) << endl;
    return 0;
}