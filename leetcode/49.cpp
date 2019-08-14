class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(auto str : strs) {
            string temp(40, '0');
            for(auto c:str) temp[c-'a']++;
            mp[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto v : mp) {
            ans.push_back(v.second);
        }
        return ans;
    }
};
