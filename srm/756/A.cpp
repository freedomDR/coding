#include <bits/stdc++.h>

using namespace std;


class ClinderellaGirls
{
public:
    //O(nlogn)
    int count(vector<int> t, vector<int> s)
    {
            vector<pair<int, int>> ts(t.size(), make_pair(0, 0));
            for(int i = 0; i < t.size(); i++)
            {
                ts[i].first = t[i];
                ts[i].second = s[i];
            }
            sort(ts.begin(), ts.end(), [](auto ts1, auto ts2){return ts1.first < ts2.first || (ts1.first == ts2.first &&  ts1.second < ts2.second);});
            int ans = 0;
            vector<int> left(ts.size(), INT_MIN), right(ts.size(), INT_MIN);
            int maxx = INT_MIN, maxx1 = INT_MIN;
            for(int i = t.size()-2; i >= 0; i--)
            {
                maxx = max(maxx, ts[i+1].second);
                maxx1 = max(maxx1, ts[i+1].first);
                right[i] = maxx;
                left[i] = maxx1;
            }
            left[t.size()-1] = ts[t.size()-1].first;
            right[t.size()-1] = ts[t.size()-1].second;
            for(int i = 0; i < t.size(); i++)
            {
                if(left[i] == ts[i].first || right[i] <= ts[i].second) ans++;
            }
            return ans;
    }

    //o(n^2)
    int count(vector<int> t, vector<int> s, int temp)
    {
        int ans = 0;
        for(int i = 0; i < t.size(); i++)
        {
            for(int j = 0; j < t.size(); j++)
            {
                if(i == j) continue;
                if(t[j] > t[i] && s[j] > s[i])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};


int main()
{
    ClinderellaGirls* app = new ClinderellaGirls();
    vector<int> t{46}, s{81};
    cout<<app->count(t, s, 1)<<endl;
    delete app;
    return 0;
}
