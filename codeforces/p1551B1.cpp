#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int n = s.size(), k = 2;
        vector<int> arr(n);
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            arr[i] = s[i]-'a';
        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[i] = i;
        sort(pos.begin(), pos.end(), [&](int i, int j) {return arr[i] < arr[j];});
        int j = 1;
        for(int i = 0, cnt = 0; i < n; i++)
        {
            if(i == 0 || arr[pos[i]] != arr[pos[i-1]]) cnt = 0;
            if(cnt == k) continue;
            if(j==k+1) j = 1;  
            ans[pos[i]] = j;
            cnt++;
            j++;
        } 
        if(j == k+1) j = 1;
        for(int i = 1; i < j; i++)
        {
            int ii = 0;
            while(ans[ii]!=i) ii++;
            ans[ii] = 0;
        }
        int ret = 0;
        for(int i = 0; i < n; i++)
            if(ans[i]==1) ret++;
        cout << ret << endl;
    }
    return 0;
}