#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.second < p2.second;
};

int main()
{
    int n, xs = 0;
    cin >> n;
    vector<pair<int, int> > p;
    while(n--)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
        xs+=x;
    }
    sort(p.begin(), p.end(), cmp);
    int ans = 0;
    int l = 0, r = p.size()-1, left = 0, right = 0;
    while(l < r)
    {
        if(left == 0 && right == 0)
        {
            left += p[l].first;
            right += p[r].first;
            continue;
        }
        ans = max(ans, p[l].second+p[r].second);
        if(left < right) {l++;left+=p[l].first;}
        else{r--;right+=p[r].first;}
    }
    if(left != right)
    {
        ans = max(ans, p[l].second+p[r].second);
    }
    cout << ans << endl;
    return 0;
}
