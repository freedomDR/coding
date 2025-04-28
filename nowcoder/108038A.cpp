#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b = "while";
    cin >> a;
    int ans = 0;
    for (int i = 0; i < b.size(); i++) {
        if (a[i]!=b[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}