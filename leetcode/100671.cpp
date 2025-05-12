#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> cnt;
        for (char c:s) {
            cnt[c]++;
        }
        int max1 = 0, max2 = 0;
        for (auto [k, v]:cnt) {
            if (k=='a'||k=='e'||k=='i'||k=='o'||k=='u') {
                max1 = max(max1, v);
            } else {
                max2 = max(max2, v);
            }
        }
        return max1+max2;
    }
};

int main()
{
    Solution s;
    cout << s.maxFreqSum("aeiaeia") << endl;
    return 0;
}