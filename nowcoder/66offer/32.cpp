class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty()) return "";
        vector<string> n;
        for(int i = 0; i < numbers.size(); i++) n.push_back(to_string(numbers[i]));
        sort(n.begin(), n.end(), [](string s1, string s2){
            return s1+s2 < s2+s1;
        });
        string ans = "";
        for(int i = 0; i < n.size(); i++) ans += n[i];
        return ans;
    }
};
