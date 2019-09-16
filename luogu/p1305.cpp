#include<bits/stdc++.h>
using namespace std;
char s[26][3];

void walk(int pos)
{
    cout << s[pos][0];
    if(s[pos][1] != '*') walk(s[pos][1]-'a');
    if(s[pos][2] != '*') walk(s[pos][2]-'a');
}

int main()
{
    int t; cin >> t;
    char st = ' ';
    while(t--)
    {
        char v[4];
        cin >> v;
        if(st == ' ') st = v[0];
        strncpy(s[v[0]-'a'], v, 3);
    }
    walk(st-'a');
}
