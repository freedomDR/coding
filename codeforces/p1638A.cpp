#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> arr(n);
        for(auto &v:arr) cin >> v;
        int l = 0;
        for(; l < n; l++)
        {
            if(arr[l] == l+1)
                cout << l+1 << " ";
            else 
                break;
        }
        if(l == n) 
        {
            cout << endl;
            continue;
        }
        int r = l;
        for(; r < n; r++)
        {
            if(arr[r] == l+1)
                break;
        }
        for(int i = r; i >= l; i--)
            cout << arr[i] << " ";
        for(int i = r+1; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}
