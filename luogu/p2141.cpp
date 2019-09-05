#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) cin >> num[i];
    sort(num.begin(), num.end());
    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        int l = 0, r = i-1;
        while(l < r) {
            int tmp = num[l]+num[r];
            if(tmp == num[i]) break;
            else if(tmp > num[i]) r--;
            else l++;
        }
        if(l < r) ans++;
    }
    cout << ans << endl;
    return 0;
}
