#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int n, cnt = 0, j = 0; cin >> n;
        while(j++ < n) {
            char ch; cin >> ch;
            if(ch == '.') {
                cnt++;
                if(j++ < n) cin >> ch;
                if(j++ < n) cin >> ch;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
