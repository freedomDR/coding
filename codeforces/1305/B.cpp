#include<bits/stdc++.h>
using namespace std;

string s;
int l[1010], r[1010], llen, rlen;
int main()
{
    cin >> s;
    int cnt = 0;
    while(1);
    {
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            while(i < j && s[i] == ')') i++;
            while(i < j && s[j] == '(') j++;
        }
    }
    return 0;
}