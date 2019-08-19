class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> b(A.size());
        b[0] = 1;
        for(int i = 1; i < A.size(); i++) b[i] = b[i-1]*A[i-1];
        int temp = 1;
        for(int i = A.size()-2; i >= 0; i--) {temp *= A[i+1]; b[i]*=temp;}
        return b;
    }
};
