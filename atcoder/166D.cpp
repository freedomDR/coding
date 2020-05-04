#include<bits/stdc++.h>

using namespace std;
long long sqr(long long s)
{
    long long ss = abs(s);
    long long l = 0, r = 1000;
    while(l<r)
    {
        long long mid = (l+r)/2;
        if(pow(mid, 5) < ss) l = mid+1;
        else r = mid;
    }
    if(s>=0) return l;
    else return -l;
}
int main()
{
    long long x;
    cin >> x;
    long long v = 0;
    while(1)
    {
        long long a = v;
        long long b = sqr(pow(a, 5)-x);
        if(pow(a, 5)-pow(b, 5) == x){cout << a <<  " " << b << endl;break;}
        a = -v;b = sqr(pow(a, 5)-x);
        if(pow(a, 5)-pow(b, 5) == x){cout << a <<  " " << b << endl;break;}
        v++;
    }
    return 0;
}