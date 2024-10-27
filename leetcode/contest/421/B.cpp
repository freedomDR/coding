#include <bits/stdc++.h>

using namespace std;

int lengthAfterTransformations(string s, int t) {
    const int MOD = 1e9+7;
    vector<int> character_cnt(26, 0);
    vector<int> tmp_character_cnt(26, 0);
    for (char c : s) { character_cnt[c-'a']++; }
    for (int i = 0; i < t; i++) {
        for (int i = 0; i < 26; i++) {
            if (i == 0) {
                tmp_character_cnt[i] = character_cnt[25];
            } else if (i == 1) {
                tmp_character_cnt[i] = (character_cnt[i-1] + character_cnt[25])%MOD;
            } else {
                tmp_character_cnt[i] = character_cnt[i-1];
            }
        }
        character_cnt = tmp_character_cnt;
    }

    int ans = 0;
    for (int val : character_cnt) {
        ans = (ans+val)%MOD;
    }
    return ans;
}

int main() {
    cout << lengthAfterTransformations("abcyy", 2) << "\n";
    cout << lengthAfterTransformations("azbk", 1) << "\n";
    return 0;
}