#include <bits/stdc++.h>

using namespace std;

vector<bool> camelMatch(vector<string>& queries, string pattern)
{
    vector<bool> ans(queries.size(), false);
    for(int i = 0; i < queries.size(); i++)
    {
        int si = 0, pi = 0;
        while(si < queries[i].size() && pi < pattern.size())
        {
            if(queries[i][si] == pattern[pi]) si++, pi++;
            else if(queries[i][si] >= 'a' && queries[i][si] <= 'z') si++;
            else break;
        }
        while(si < queries[i].size() && queries[i][si] >= 'a' && queries[i][si] <= 'z') si++;
        if(si == queries[i].size() && pi == pattern.size()) ans[i] = true;
    }
    return ans;
}

int main()
{
    vector<string> queries;
    int n;
    string pattern;
    cin>>n;
    for(int i = 0; i < n; i++) 
    {
        string s;cin>>s;
        queries.push_back(s);
    }
    cin>>pattern;
    vector<bool> ans = camelMatch(queries, pattern);
    for(bool v:ans) cout<<v<<" ";
    return 0;
}
