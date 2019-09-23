#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int d[1000010];
int main()
{
    int n; cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
        if(s[i] == 'X') d[i] = INT_MAX;
        else d[i] = 0;
    int pos = 0;
    while(pos < n)
    {
        if(d[pos] != 0) pos++;
        else
        {
            for(int j = pos-1, v = 1; j >= 0 && d[j] != 0; j--, v++)
            {
                if(d[j] == v) continue;
                d[j] = min(d[j], v);
            }
            for(int j = pos+1, v = 1; j < n && d[j] != 0; j++, v++)
            {
                d[j] = min(d[j], v);
            }
            pos++;
        }
    }
    for(int i = 0; i < n; i++) cout << d[i] << " ";
    return 0;
}
