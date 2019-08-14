class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return;
        int temp = 0;
        for(int i = 0; i < data.size(); i++) temp ^= data[i];
        int index = 1;
        while((temp&(1<<index)) == 0) index++;
        for(int i = 0; i < data.size(); i++){
            if(data[i]&(1<<index)){
                *num1 ^= data[i];
            }else{
                *num2 ^= data[i];
            }
        }
    }
};
