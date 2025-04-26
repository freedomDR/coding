#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == c && a == 0 && b != 0)
        cout << "YES" << endl;
    else if (a != c && a * c == -1 && b == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}