#include<bits/stdc++.h>
using namespace std;

int t[100001], len, d1[100001], d2[100001];
bool cmp(int x1, int x2) {return x1 > x2;}
int main()
{
    int x;
    while((cin >> x)) t[++len] = x;
    int l1 = 1, l2 = 1;
    d1[l1] = d2[l2] = t[1];
    for(int i = 2; i <= len; i++)
    {
        if(t[i] <= d1[l1]) d1[++l1] = t[i];
        else
        {
            *upper_bound(d1+1, d1+l1+1, t[i], cmp) = t[i];
        }
        if(t[i] > d2[l2]) d2[++l2] = t[i];
        else
        {
            *lower_bound(d2+1, d2+l2+1, t[i]) = t[i];
        }
    }
    cout << l1 << endl << l2 << endl;
    return 0;
}
