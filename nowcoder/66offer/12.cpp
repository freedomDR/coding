class Solution {
public:
    double Power(double base, int exponent) {
        int symbol = (exponent < 0)?-1:1;
        double ans = 1.0;
        exponent = abs(exponent);
        if(exponent == 0) return ans;
        while(exponent) {
            if(exponent&1) {
                ans *= base;
            }
            base *= base;
            exponent >>= 1;
        }
        ans = symbol < 0? 1.0/ans : ans;
        return ans;
    }
};
