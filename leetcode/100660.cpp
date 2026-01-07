#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    string resultingString(string s) {
        stack<int> st;
        for (auto c:s) {
            int x = c-'a';
            if (!st.empty()&&(abs(st.top()-x)==1||abs(st.top()-x)==25)) st.pop();
            else st.push(x);
        }
        string res = "";
        while (!st.empty()) {
            res.push_back('a'+st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};