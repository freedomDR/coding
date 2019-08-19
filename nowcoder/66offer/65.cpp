class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<bool> flag(strlen(matrix), false);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(slove(i, j, flag, matrix, str, 0, rows, cols)) return true;
            }
        }
        return false;
    }
    
    bool slove(int i, int j, vector<bool>& flag, char* matrix, char* str, int len, int rows, int cols){
        int index = i*cols+j;
        if(i<0||i>=rows||j<0||j>=cols|| flag[index] ||matrix[index] != str[len]) return false;
        if(len == strlen(str)-1) return true;
        flag[index] = true;
        if(slove(i+1, j, flag, matrix, str, len+1, rows, cols)||
            slove(i-1, j, flag, matrix, str, len+1, rows, cols)||
            slove(i, j+1, flag, matrix, str, len+1, rows, cols)||
            slove(i, j-1, flag, matrix, str, len+1, rows, cols)) return true;
        flag[index] = false;
        return false;
    }


};
