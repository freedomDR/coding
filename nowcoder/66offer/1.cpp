class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i = array.size()-1, j = 0;
        while(i >= 0 && j < array[0].size()) {
            if(array[i][j] == target) return true;
            else if(array[i][j] > target) --i;
            else ++j;
        }
        return false;
    }
};
