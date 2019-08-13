class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        if(!matrix[0].size() || !matrix.size()) return ans;
        int lay = 0;
        while(true){
            int li = 0+lay, lj = 0+lay, ri = matrix.size()-1-lay, rj = matrix[0].size()-1-lay;
            if(li>ri||lj>rj) break;
            for(int i = lj; i <= rj; i++) ans.push_back(matrix[li][i]);
            for(int i = li+1; i <= ri; i++) ans.push_back(matrix[i][rj]);
            if(li != ri)for(int i = rj-1; i >= li; i--) ans.push_back(matrix[ri][i]);
            if(lj != rj)for(int i = ri-1; i >= li+1; i--) ans.push_back(matrix[i][lj]);
            lay++;
        }
        return ans;
    }
};
