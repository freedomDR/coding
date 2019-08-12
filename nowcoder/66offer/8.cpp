class Solution {
public:
    int jumpFloor(int n) {
        int f1 = 1, f2 = 2;
        n -= 1;
        while(n-- > 0) {
            f2 += f1;
            f1 = f2 - f1;
        }
        return f1;
    }
};
