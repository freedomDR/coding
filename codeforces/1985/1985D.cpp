#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--) 
    {
        int n, m;
        cin >> n >> m;
        std::vector<std::vector<char>> arr(n, std::vector<char>(m, '.'));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> arr[i][j];
        
        int x, y, max_len = 0;
        for(int i = 0; i < n; i++)
        {
            int x_len = 0;
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == '#')
                {
                    x_len++;
                }
            }
            if (x_len > max_len)
            {
                max_len = x_len;
                x = i+1;
            }
        }
        for(int i = 0; i < m; i++)
        {
            int x_len = 0;
            for(int j = 0; j < n; j++)
            {
                if(arr[j][i] == '#')
                {
                    x_len++;
                }
            }
            if (x_len == max_len)
            {
                y = i+1;
            }
        }        

        cout << x << " " << y << endl;
    }
    return 0;
}