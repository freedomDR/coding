#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    int z, e, r, o, n;
    z = 0; e = 0; r = 0; o = 0; n = 0;
    for(int i = 0; i < N; i++)
    {
        char v;
        cin >> v;
        if(v == 'z') z++;
        if(v == 'n') n++;
        if(v == 'r') r++;
        if(v == 'o') o++;
        if(v == 'e') e++;
    }       
    int ones = min(o, min(n, e));
    e -= ones; o -=ones;
    int zeros = min(min(z, e), min(r, o));
    for(int i = 0; i < ones; i++) cout <<"1 ";
    for(int i = 0; i < zeros; i++) cout <<"0 ";
}
