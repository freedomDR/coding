class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        int size = sequence.size();
        while(--size){
            int l = 0, r = size-1;
            while(l < size && sequence[l] < sequence[size]) l++;
            while(r >= 0 && sequence[r] > sequence[size]) r--;
            if(l < r) return false;
        }
        return true;
    }
};
