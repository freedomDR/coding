class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> exra;
        for(int i = 0, j = 0; i < pushV.size(); i++){
            exra.push(pushV[i]);
            while(j<popV.size()&&exra.top() == popV[j]){
                exra.pop();j++;
            }
        }
        return exra.empty();
    }
};
