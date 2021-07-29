//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, t;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<string> arr(2*n-1);
        vector<bool> f(2*n-1, true);
        for(int i = 0; i < 2*n-1; i++)
            cin >> arr[i];
        vector<int> cnt(26);
        for(int i = 0; i < m; i++)
        {
            int ans = 0;
            for(int j = 0; j < 2*n-1; j++)
            {
                if(j < n) ans += arr[j][i]-'a';
                else ans -= arr[j][i]-'a';
            }
            cout << (char)(ans+'a');
        }
        cout << endl;
    }
}