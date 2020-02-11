#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n; n *= 2;
        vector<int> arr(n);
        for(auto &x:arr) cin >> x;
        sort(arr.begin(), arr.end());
        cout << (arr[n/2]-arr[n/2-1]) << endl;
    }
    return 0;
}
