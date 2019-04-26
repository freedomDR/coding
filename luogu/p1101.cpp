#include <bits/stdc++.h>
/*
 *
 *脑子短路了
 *
 *
 */
using namespace std;
int n;
int ans[101][101];
char s[101][101];
bool visit[101][101];
string pattern = "yizhong";
int add[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
vector<pair<int, int>> path;
void dfs(int r, int l)
{
    for(int i = 0; i < 8; i++)
    {
        int len = 0, rr = r, ll = l;
        while(len < pattern.size())
        {
            if(rr >= 0 && rr < n && ll >= 0 && ll < n && pattern[len] == s[rr][ll])
            {
                rr += add[i][0]; ll += add[i][1];
                len++;
            }
            else break;
        }
        if(len == pattern.size()) 
        {
            rr = r; ll = l;
            while(len--) 
            {
                ans[rr][ll] = 1;
                rr += add[i][0]; ll += add[i][1];
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(s[i][j] == 'y') dfs(i, j);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(ans[i][j]) cout<<s[i][j]<<"";
            else cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
