class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL || length == 0) return;
        int blankCnt = 0;
        for(int i = 0; i < length; i++) {
            if(str[i] == ' ') blankCnt++;
        }
        for(int i = length-1; i >= 0; i--) {
            if(str[i] != ' ') str[i+blankCnt*2] = str[i];
            else{
                blankCnt--;
                str[i+blankCnt*2] = '%';
                str[i+blankCnt*2+1] = '2';
                str[i+blankCnt*2+2] = '0';
            }
        }
	}
};
