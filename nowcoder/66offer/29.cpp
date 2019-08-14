class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ans;
        if(k == 0 || input.empty() || k > input.size()) return ans;
        priority_queue<int, vector<int>, greater<int>> t;
        for(int i = 0; i < input.size(); i++){
            t.push(input[i]);
        }
        while(!t.empty()&&k-- > 0){
            ans.push_back(t.top());
            t.pop();
        }
        return ans;
    }
};
