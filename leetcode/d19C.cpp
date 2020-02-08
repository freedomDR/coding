class Solution {
public:
    double angleClock(int hour, int minutes) {
        double v1 = minutes*6;
        double v2 = 0.0;
        if(hour == 12) hour = 0;
        v2 = hour*30;
        v2 += (1.0*minutes/60)*30;
        return min(abs(v1-v2), 360-abs(v1-v2));
    }
};
