#include<bits/stdc++.h>
using namespace std;

int sloveDP(string w1, string w2)
{
    int w1Len = w1.size(), w2Len = w2.size();
    vector<vector<int>> dp(w1Len+1, vector<int>(w2Len+1));
    auto mins = [](int v1, int v2, int v3){
        return min(min(v1,v2), v3);
    };
    for(int i = 0; i <= w1Len; i++) {
        dp[i][0] = i;
    }
    for(int i = 0; i <= w2Len; i++) {
        dp[0][i] = i;
    }
    for(int i = 1; i <= w1Len; i++){
        for(int j = 1; j <= w2Len; j++) {
            if(w1[i-1] == w2[j-1]) {
                dp[i][j] = 1 + mins(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]-1);
            }else{
                dp[i][j] = 1 + mins(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }
    return dp[w1Len][w2Len];
}

int main()
{
    string w1, w2;
    cin >> w1 >> w2;
    cout << sloveDP(w1, w2) << endl;
    return 0;
}
