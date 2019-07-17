#include <bits/stdc++.h>

using namespace std;

int videoStitching(vector<vector<int>>& clips, int T)
{
    sort(clips.begin(), clips.end(), [](vector<int>& c1, vector<int>& c2){return c1[0] == c2[0] ? c1[1] < c2[1] : c1[0] < c2[0];});
    vector<int> dp(T+1, INT_MAX);
    /* for(vector<int>& c:clips) */
    /* { */
    /*     for(int cc:c) cout<<cc<<" "; */
    /*     cout<<endl; */
    /* } */
    dp[0] = 0;
    for(int i = 0; i <= T; i++)
    {
        for(int j = 0; j < clips.size() && clips[j][0] <= i; j++)
        {
            if(clips[j][1] >= i) dp[i] = min(dp[i], dp[clips[j][0]]+1);
        }
    }
    return dp[T] == INT_MAX ? -1 : dp[T];
}

int main()
{
    int T, n;
    cin>>n;
    vector<vector<int>> clips(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++)
    {
        cin>>clips[i][0]>>clips[i][1];
    }
    cin>>T;
    cout<<videoStitching(clips, T)<<endl;
    return 0;
}
