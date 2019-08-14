#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        bool ans = true;
        for(int i = 0; i < n-1 && ans; i++) {
            if(h[i] < h[i+1]-k) {
                m -= h[i+1]-k-h[i];
                if(m < 0) ans = false;
            }else {
                m += h[i]-max(0, h[i+1]-k);
            }
        }
        cout << (ans?"YES":"NO") << endl;
    }
    return 0;
}

