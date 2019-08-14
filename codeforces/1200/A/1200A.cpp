#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> ans(10);
    cin >> n;
    while(n--) {
        char e; cin >> e;
        if(e == 'L') {
            int i = 0;
            while(ans[i++] == 1);
            ans[i-1] = 1;
        }else if(e == 'R') {
            int i = 9;
            while(ans[i--] == 1);
            ans[i+1] = 1;
        }else {
            int p = e-'0';
            ans[p] = 0;
        }
    }
    for(int i = 0; i < 10; i++) cout << ans[i];
    cout << endl;
    return 0;
}
