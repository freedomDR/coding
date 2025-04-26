#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> du(n+1);
        for (int i = 1; i <= m; i++) {
            int x,  y;
            cin >> x >> y;
            du[x]++;
            du[y]--;
        }
        int a = 0;
        for (int i = 1; i <= n; i++) {
            if (du[i]==1) a++;
        }
        if (a%2 && n%2==0)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}