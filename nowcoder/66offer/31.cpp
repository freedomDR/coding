class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ans = 0;
        for(int i = 1; i <= n; i*=10){
            int temp = i*10;
            ans += n/temp*i + min(i, max(n%temp-i+1, 0));
        }
        return ans;
    }
};
