#include<bits/stdc++.h>
using namespace std;

int sloveDP(vector<vector<char>>& m)
{
    int rows = m.size(), columns = m[0].size();
    int ans = 0;
    vector<int> h(columns), l(columns), r(columns, columns);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++) {
            if(m[i][j] == '1') h[j]++;
            else h[j] = 0;
        }
        for(int j = 0, left = 0; j < columns; j++) {
            if(m[i][j] == '1') l[j] = max(l[j], left);
            else {l[j] = 0; left = j+1;}
        }
        for(int j = columns-1, right = columns; j >= 0; j--) {
            if(m[i][j] == '1') r[j] = min(r[j], right);
            else {r[j] = columns; right = j;}
        }
        for(int j = 0; j < columns; j++) {
            ans = max(ans,  h[j]*(r[j]-l[j]));
        }
    }
    return ans;
}

int main()
{
    int m, n; cin >> m >> n;
    vector<vector<char>> matrix(m, vector<char>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << sloveDP(matrix) << endl;
    return 0;
}
