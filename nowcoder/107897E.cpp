#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int & v:arr) cin >> v;
        sort(arr.begin(), arr.end());
        set<int> pos;
        bool can = true;
        for (int i = n-1; i >= 0; i--) {
            int pos1 = arr[i]+1;
            int pos2 = arr[i]-1;
            if (pos.count(pos1)==0) 
                pos.insert(pos1);
            else if (pos.count(pos2)==0)
                pos.insert(pos2);
            else {
                can = false;
                break;
            }
        }
        int sums = 0, pre = 0;
        for (int v:pos) {
            sums += (v-pre);
            pre = v;
            sums -= 2;
            if (sums < 0) {
                can = false;
                break;
            }
        }
        cout << (can ? "YES" : "NO") << endl;
    }
    return 0;
}