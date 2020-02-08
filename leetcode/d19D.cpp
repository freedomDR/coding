class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size();
        vector<bool> vis(len, false);
        map<int, vector<int>> m;
        for(int i = 0; i < len; i++)
        {
            m[arr[i]].push_back(i);
        }
        int step = 0;
        vector<int> p;
        p.push_back(0);
        vis[0] = true;
        while(1)
        {
            vector<int> temp;
            for(auto &it:p)
            {
                if(it == len-1) return step;
                if(it-1>=0&&!vis[it-1]) temp.push_back(it-1),vis[it-1]=true;
                if(it+1<len&&!vis[it+1]) temp.push_back(it+1), vis[it+1]=true;
                for(auto &j:m[arr[it]])
                {
                    if(j != it &&!vis[j]) temp.push_back(j), vis[j]=true;
                }
                m[arr[it]].clear();
            }
            step++;
            swap(temp, p);
        }
        return step;
    }
};
