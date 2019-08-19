class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        return slove(visit, 0, 0, rows, cols, threshold);
    }
    int slove(vector<vector<bool>>& visit, int i, int j, int rows, int cols, int threshold)
    {
        if(i<0||i>=rows||j<0||j>=cols||visit[i][j]||(calc(i)+calc(j)>threshold)) return 0;
        visit[i][j] = true;
        return slove(visit,i+1,j,rows,cols,threshold)+
            slove(visit,i-1,j,rows,cols,threshold)+
            slove(visit,i,j+1,rows,cols,threshold)+
            slove(visit,i,j-1,rows,cols,threshold)+1;
    }
    
    int calc(int num)
    {
        int ans = 0;
        while(num > 0){
            ans += num%10;
            num/=10;
        }
        return ans;
    }
};
