class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ans;
        deque<int> d;
        for(int i = 0; i < num.size(); i++) {
            while(d.size() && num[d.back()] <= num[i]) d.pop_back();
            while(d.size() && i-d.front()+1 > size) d.pop_front();
            d.push_back(i);
            if(size&&i+1>=size)ans.push_back(num[d.front()]);
        }
        return ans;
    }
};
