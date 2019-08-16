class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5) return false;
        int maxN = -1, minN = 14, flag = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] == 0) continue;
            if((flag>>numbers[i]) == 1) return false;
            flag |= (1<<numbers[i]);
            maxN = max(maxN, numbers[i]);
            minN = min(minN, numbers[i]);
            if(maxN - minN >= 5) return false;
        }
        return true;
    }
};
