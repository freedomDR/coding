#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> days(n);
    for(int i = 0; i < n; i++) cin >> days[i];
    int ans = 1, tmp = 1;
    for(int i = 1; i < n; i++) {
        if(days[i]>days[i-1]) tmp++;
        else {
            ans = max(ans, tmp);
            tmp = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
