#include<bits/stdc++.h>
using namespace std;
const int MAX = 510;
char a[MAX], b[MAX];
int c[MAX];
int main()
{
    cin >> a >> b;
    int a_len = strlen(a), b_len = strlen(b);
    int p1 = a_len-1, p2 = b_len-1, p = 0;
    while(p1 >= 0 && p2 >= 0)
    {
        c[p] += (a[p1--]-'0')+(b[p2--]-'0');
        if(c[p] > 9)
        {
            c[p] %= 10;
            c[p+1]++;
        }
        p++;
    }
    while(p1 >= 0)
    {
        c[p] += (a[p1--]-'0');
        if(c[p] > 9)
        {
            c[p] %= 10;
            c[p+1]++;
        }
        p++;
    }
    while(p2 >= 0)
    {
        c[p] += (b[p2--]-'0');
        if(c[p] > 9)
        {
            c[p] %= 10;
            c[p+1]++;
        }
        p++;
    }
    if(c[p] == 0) p--;
    while(p >= 0) cout << c[p--];
    cout << endl;
}
