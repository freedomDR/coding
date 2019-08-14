class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0;
        for(int i = 0; i < nums.size(); i++) {
            if( l >= i) {
                l = max(i+nums[i], l);
            }
            else {
                return false;
            }
        }
        return true;
    }
};
