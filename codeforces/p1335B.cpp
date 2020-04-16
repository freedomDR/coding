#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        for(int i = 0, j = 0; i < n; i++, j++)
        {
            char c = 'a'+(j%b);
            cout << c;
        }
        cout << endl;
    }
    return 0;
}