#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main() {
    int n, r; cin >> n >> r;
    vector<pii> pos, neg;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if(b >= 0) pos.push_back(make_pair(a, b));
        else neg.push_back(make_pair(a, b));
    }
    sort(pos.begin(), pos.end());
    int ans = 0;
    for(auto &it:pos) {
        if(r>=it.first){
            r+=it.second;
            ans++;
        }
    }
    sort(neg.begin(), neg.end(), [](pii p1, pii p2){return p1.first+p1.second > p2.first+p2.second;});
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto &it:neg) {
        r += it.second;
        pq.push(it.second);
        if(r < max(it.first+it.second, 0)) {
            r -= pq.top();
            pq.pop();
        }
        /* if(r >= it.first) { */
        /*     pq.push(it.second); */
        /*     r += it.second; */
        /*     if(r < 0) {pq.pop();r-=it.second;} */
        /* } */
    }
    ans += pq.size();
    cout << (ans==n?"YES":"NO") << endl;
    /* cout << ans << endl; */
    return 0;
}
