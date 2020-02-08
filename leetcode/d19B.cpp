class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for(int i = 1; i < arr.size(); i++)
        {
            prefix[i] = prefix[i-1] + arr[i];
        }
        int ans = 0;
        for(int i = k; i < arr.size(); i++)
        {
            if(prefix[i]-prefix[i-k]>=threshold*k) ans++;
        }
        if(prefix[k-1]>=threshold*k) ans++;
        return ans;
    }
};
