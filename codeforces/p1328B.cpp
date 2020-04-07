#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;
        long long len = 1;
        while(len*(len+1)/2 < k) len++;
        long long remain = (len*(len+1)/2)-k;
        string ans(n, 'a');
        ans[len] = 'b';
        ans[len-remain-1] = 'b';
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}