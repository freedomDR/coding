class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i = 0; i < array.size(); i++) {
            if(array[i]%2 == 0) continue;
            int ori = array[i], j;
            for(j = i-1; j >= 0; j--) {
                if(array[j]%2 == 0) array[j+1] = array[j];
                else break;
            }
            array[j+1] = ori;
        }
    }
};
