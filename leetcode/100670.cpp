#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> cnt(26);
        for (char c:s) {
            cnt[c-'a']++;
        }
        vector<int> arr;
        for (int c:cnt) {
            if (c>0)
                arr.push_back(c);
        }
        ranges::sort(arr);
        int ans = 0;
        if (k>=arr.size()) return 0;
        for (int i = 0; i < arr.size()-k; i++) {
            ans += arr[i];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.minDeletion("abc", 2) << endl;
    cout << s.minDeletion("aabb", 2) << endl;
    cout << s.minDeletion("yyyzz", 1) << endl;
    return 0;
}