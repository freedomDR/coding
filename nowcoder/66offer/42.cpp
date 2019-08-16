class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int l = 0, r = array.size()-1;
        vector<int> ans;
        while(l < r){
            if(array[l]+array[r] == sum){ans.push_back(array[l]); ans.push_back(array[r]); break;}
            if(array[l]+array[r] < sum) {l++;continue;}
            if(array[l]+array[r] > sum) {r--;continue;}
        }
        return ans;
    }
};
