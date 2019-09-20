#include<bits/stdc++.h>
using namespace std;
int f[26], ans[500500];
int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++)
    {
        int win = false;
        for(int j = 0; j < s[i]-'a'; j++)
        {
            if(f[j] > 0) win = true;
        }
        cout << (win?"Ann":"Mike") << endl;
        f[s[i]-'a']++;
    }
    return 0;
}
