#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int len = arr[0].length();
    for (int i = 1; i < n; i++)
        len = gcd(len, arr[i].length());
    vector<vector<int>> freq(len, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i].length(); j++) {
            freq[j%len][arr[i][j] - 'a']++;
        }
    }
    int ans = 0;
    for (int i = 0; i < len; i++) {
        int max_char = 0;
        ans += accumulate(freq[i].begin(), freq[i].end(), 0)-*max_element(freq[i].begin(), freq[i].end());
    }
    cout << ans << endl;
    return 0;
}