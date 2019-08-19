class Solution {
public:
    int StrToInt(string str) {
        int pos = 0, postive = 1;
        if(str[pos] == '-') {postive = -1;pos++;} 
        else if(str[pos] == '+') {postive = 1;pos++;}
        else if(str[pos] < '0' || str[pos] > '9') return 0;
        else ;
        int ans = 0;
        while(pos < str.size()){
            if(str[pos] < '0' || str[pos] > '9') return 0;
            ans = ans*10 + (str[pos]-'0');
            pos++;
        }
        return ans*postive;
    }
};
