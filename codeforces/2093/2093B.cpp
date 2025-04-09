#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string n;
        cin >> n;
        int left_zero = 0;
        bool find_digit = false;
        for (int i = n.size()-1; i >= 0; i--) {
            if (n[i] == '0' && find_digit) {
                left_zero++;
            } else if (n[i] != '0') {
                find_digit = true;
            }
        }
        cout << n.size()-left_zero-1 << endl; 
    }
    return 0;
}