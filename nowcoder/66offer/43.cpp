class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if(len == 0) return "";
        n %= len;
        for(int i = 0, j = n-1; i < j; i++, j--) swap(str[i],str[j]);
        for(int i = n, j = len-1; i < j; i++, j--) swap(str[i],str[j]);
        for(int i = 0, j = len-1; i < j; i++, j--) swap(str[i],str[j]);
        return str;
    }
};
