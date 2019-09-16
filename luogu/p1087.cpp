#include<bits/stdc++.h>
using namespace std;
int n;
char s[1100];
int suffix[1100];

void walk(int st, int length)
{
    if(length == 1)
    {
        /* cout << st << " " << s[st] << endl; */
        cout << (s[st] == '0'?'B':'I');
        return;
    }
    walk(st, length/2);
    walk(st+length/2, length/2);
    int t = suffix[st+length-1]-suffix[st-1];
    assert( t <= length );
    if(t == length) cout << 'I';
    else if(t == 0) cout << 'B';
    else cout << 'F';
}

int main()
{
    cin >> n >> (s+1);
    for(int i = 1; i <= (int)pow(2, n); i++)
    {
        suffix[i] = suffix[i-1] + s[i] - '0';
    }
    walk(1, (int)pow(2, n));
    return 0;
}
