class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ans;
        int l = 1, r = 2;
        while(l < r) {
            int cur = (l+r)*(r-l+1)/2;
            if(cur == sum) {
                vector<int> item;
                for(int i = l; i <= r; i++) {
                    item.push_back(i);
                }
                ans.push_back(item);
                l++;
            }else if(cur < sum){
                r++;
            }else{
                l++;
            }
        }
        return ans;
    }
};
