#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;cin >> n;
        vector<bool> f(n+1);
        vector<int> arr(n);
        for(auto &v:arr) cin >> v;
        int pre = 0, ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(f[arr[i]] == false)
            {
                f[arr[i]] = true;
            }else
            {
                while(arr[pre] != arr[i])
                {
                    f[arr[pre++]] = false;
                }
                ans = min(ans, i-pre+1);
                pre++;
            }
        }
        cout << (ans == INT_MAX?-1:ans) << endl;
    }
}
