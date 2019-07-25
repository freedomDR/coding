#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q; cin >> q;
    while(q--) {
        long long n, k, sums = 0, odds = 0;
        cin >> n >> k;
        vector<long long> ans;
        for(int i = 0; i < n; i++) {
            long long v; cin >> v;
            sums += v;
            if(sums%2 == 1) {odds++;ans.push_back(i+1);sums=0;}
        }
        if(odds < k || (odds-k)%2 == 1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            int p = 0;
            ans.pop_back();
            ans.push_back(n);
            while(p < (odds-k)) p++;
            for(; p < int(ans.size()); p++)  {
                cout << ans[p] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
