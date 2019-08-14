class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ans = -(1e9), t = 0;
        for(int i = 0; i < array.size(); i++) {
            t += array[i];
            t = max(array[i], t);
            ans = max(ans, t);
        }
        return ans;
    }
};
