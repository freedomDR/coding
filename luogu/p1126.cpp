#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    int x, y, end_x, end_y;
    cin >> x >> y >> end_x >> end_y;
    map<char, int> k1;
    map<int, char> k1;
    for(int i = 0; i < 4; i++)
        
    return 0;
}