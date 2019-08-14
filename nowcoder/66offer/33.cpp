class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7) return index;
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for(int i = 1; i < index; i++){
            res[i] = min(min(res[t2]*2, res[t3]*3), res[t5]*5);
            if(res[i] == res[t2]*2) t2++;
            if(res[i] == res[t3]*3) t3++;
            if(res[i] == res[t5]*5) t5++;
        }
        return res[index-1];
    }
};
