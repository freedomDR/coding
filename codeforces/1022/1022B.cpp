#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int p = 0;
        if (x == 0) {
            if (n==1) {
                cout << "-1" << endl;
                continue;
            }
            long long ans = (n%2?((n-1)+4):n);
            cout << ans << endl;
        } else if (x==1) {
            if (n%2) {
                cout << n << endl;
            } else {
                cout << (n-1)+4 << endl;
            }
        } else {
            int sums = 0;
            string s;
            while(x) {
                if (x%2)
                    s.push_back('1');
                else
                    s.push_back('0');
                x = x/2;
            }
            ranges::reverse(s);
            //cout << s << endl;
            int ans = 0;
            int used_one = 0;
            for (int i = 0, p = s.size()-1; i < s.size()-1; i++, p--) {
                if(s[i]=='1') {
                    used_one += 1;
                    ans += (1<<p);
                }
            }
            //cout << used_one << " " << s.back() << endl;
            if (s.back()=='1') {
                int remain_one = max(0, n-used_one);
                if (remain_one%2) ans += remain_one;
                else ans += remain_one+1;
            } else {
                int remain_one = max(0, n-used_one);
                //cout << remain_one << endl;
                if (remain_one%2) ans += remain_one+1;
                else ans += remain_one;
            }
            cout << ans << endl;
        }
    }
    return 0;
}