#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> allPossibleFBT(int n)
{
    int sz = (n+1)/2+1;
    vector<vector<TreeNode*>> dp(sz);
    if(n%2==0) return dp[0];
    dp[1].push_back(new TreeNode());
    for(int i = 2; i < sz; i++)
    {
        for(int j = 1; j < i; j++)
        {
            for(auto left:dp[j])
            {
                for(auto right:dp[i-j])
                {
                    dp[i].push_back(new TreeNode(0, left, right));
                }
            }
        }
    }
    return dp[sz-1];
}

int main()
{
    return 0;
}