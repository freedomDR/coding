class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0) return 0;
        int cnt = 0, pos = -1, l = 0, r = data.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(data[mid] <= k) l = mid+1;
            else r = mid;
        }
        //if(pos == -1) return 0;
        //for(int i = pos-1;i>=0&&data[i]==k;i--) cnt++;
        //for(int i = pos+1;i<data.size()&&data[i]==k;i++) cnt++;
        for(int i = l-1;i>=0&&data[i]==k;i--) cnt++;
        return cnt;
    }
};
