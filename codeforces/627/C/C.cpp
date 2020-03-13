#include<bits/stdc++.h>

using namespace std;
char s[200500];
int len;
int t;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        len = strlen(s+1);
        int d = 0, last = 0;
        for(int i = 1; i <= len; i++)
        {
            if(s[i] == 'R')
            {
                d = max(d, i-last);
                last = i;
            }
        }
        if(d == 0) d = len+1;
        cout << d << endl;
    }   
    return 0;
}