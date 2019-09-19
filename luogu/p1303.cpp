#include<bits/stdc++.h>
using namespace std;
const int N = 4100;
char x[N], y[N];
int a[N], b[N], c[N]; 
int main()
{
    cin >> x >> y;
    a[0] = strlen(x), b[0] = strlen(y);
    for(int i = 1; i <= a[0]; i++) a[i] = x[a[0]-i] - '0';
    for(int i = 1; i <= b[0]; i++) b[i] = y[b[0]-i] - '0';
    for(int i = 1; i <= a[0]; i++)
        for(int j = 1; j <= b[0]; j++)
            c[i+j-1] += a[i]*b[j];
    int len = a[0]+b[0];
    for(int i = 1; i < len; i++)
        if(c[i] > 9)
        {
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
    while(c[len] == 0 && len > 1) len--;
    for(int i = len; i >= 1; i--)
        cout << c[i];
    cout << endl;
    return 0;
}
