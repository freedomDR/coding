class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        int ans = numbers[0], cnt = 1;
        for(int i = 1; i < numbers.size(); i++){
            if(ans == numbers[i]) cnt++;
            else cnt--;
            if(cnt == 0){
                ans = numbers[i];
                cnt = 1;
            }
        }
        cnt = 0;
        for(int i = 0; i < numbers.size(); i++) 
            if(numbers[i] == ans) cnt++;
        if(cnt > numbers.size()/2) return ans;
        else return 0;
    }
};
