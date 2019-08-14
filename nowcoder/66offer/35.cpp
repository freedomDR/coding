class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty()) return 0;
        vector<int> copy(data.size());
        return count(data, copy, 0, data.size()-1) % (int)(1e9+7);
    }
    
    long long count(vector<int>& data, vector<int>& copy, int l, int r){
        if(l == r) return 0;
        int mid = l + (r-l)/2;
        long long left = count(data, copy, l, mid);
        long long right = count(data, copy, mid+1, r);
        int end1 = mid, end2 = r, cnt = 0, end_copy = r;
        while(end1 >= l && end2 > mid){
            if(data[end1] > data[end2]){
                copy[end_copy--] = data[end1--];
                cnt += end2-mid;
                cnt %= (int)(1e9+7);
            }else{
                copy[end_copy--] = data[end2--];
            }
        }
        for(;end1>=l;) copy[end_copy--] = data[end1--];
        for(;end2>mid;) copy[end_copy--] = data[end2--];
        for(int i = l; i <= r; i++) data[i] = copy[i];
        return (left+right+cnt)%(int)(1e9+7);
    }
};
