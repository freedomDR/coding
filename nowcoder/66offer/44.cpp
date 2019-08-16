class Solution {
public:
    string ReverseSentence(string str) {
        string ans = "", temp = "";
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' ') {ans = " "+temp+ans; temp = "";}
            else temp += str[i];
        }
        if(temp.size()) ans = temp+ans;
        return ans;
    }
};
