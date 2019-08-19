class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<int> list;
        for (int i = 0; i < n; i ++) {
            list.push_back(i);
        }
         
        int bt = 0;
        while (list.size() > 1) {
            bt = (bt + m - 1) % list.size();
            list.erase(list.begin()+bt);
        }
         
        return list.size() == 1 ? list[0] : -1;
    }
};
