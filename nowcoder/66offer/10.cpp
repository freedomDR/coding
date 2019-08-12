class Solution {
public:
    int rectCover(int number) {
        if(number == 0) return 0;
        if(number == 1) return 1;
        if(number == 2) return 2;
        int f1 = 1, f2 = 2;
        number--;
        while(number-->0){
            f2 += f1;
            f1 = f2-f1;
        }
        return f1;
    }
};
