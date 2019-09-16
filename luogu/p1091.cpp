#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    vector<int> student(N);
    for(int i = 0; i < N; i++) cin >> student[i];
    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        int lans = 0, rans = 0;
        if(i != 0)
        {
            vector<int> dp(i+1);
            for(int j = 0; j <= i; j++)
            {
                for(int k = 0; k < j; k++)
                {
                    if(student[k] < student[j] && dp[j] < dp[k]+1)
                        dp[j] = dp[k]+1;
                }
            }
        }
    }
    return 0;
}
