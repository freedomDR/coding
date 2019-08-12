class Solution {
public:
    int minNumberInRotateArray(vector<int> arr) {
        if(arr.size() == 0) return 0;
        return bs(arr, 0, arr.size()-1);
    }
    
    int bs(vector<int>& arr, int lo, int hi) {
        if(lo>=hi) return arr[lo];
        if(arr[lo] < arr[hi]) return arr[lo];
        int mid = lo + (hi-lo)/2;
        if(arr[lo] < arr[mid]) return bs(arr, mid, hi);
        else if(arr[lo] > arr[mid]) return bs(arr, lo, mid);
        else return bs(arr, lo+1, hi);
    }
};
