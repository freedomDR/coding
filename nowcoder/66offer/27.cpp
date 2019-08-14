class Solution {
public:
    vector<string> ans;
    string temp = "";
    vector<string> Permutation(string str) {
        if(str.empty()) return ans;
        sort(str.begin(), str.end());
        vector<bool> visit(str.size(), false);
        slove(str.size(), str, visit);
        return ans;
    }
    void slove(int len, string& s, vector<bool>& visit){
        if(len == 0){
            ans.push_back(temp);
        }else{
            for(int i = 0; i < s.size(); i++){
                if(!visit[i]){
                    visit[i] = true;
                    temp.push_back(s[i]);
                    slove(len-1,s,visit);
                    temp.pop_back();
                    visit[i] = false;
                    while(i+1<s.size()&&s[i+1]==s[i]) i++;
                }
            }
        }
    }
};
