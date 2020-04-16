#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        sort(a.begin(), a.end());
        int l = 0, r = n-1;
        int f = 1;
        for(int i = 0; i < n; i++)
        {
            if(f) 
            {
                cout << a[r--] << " ";
                f = 0;
            }else
            {
                cout << a[l++] << " ";
                f = 1;
            }
        }
        cout << endl;
    }
    return 0;
}