#include <bits/stdc++.h>

using namespace std;

string getPermutation(int n, int k)
{
    string ans = "";
    vector<bool> visit(n+1, false);
    vector<int> fac(n+1);
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = i*fac[i-1];
    for(int i = 1; i <= n; i++)
    {
        int pos = k/fac[n-1];
        ans.append(string('1'+pos));

    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<getPermutation(n, k)<<endl;
    return 0;
}
