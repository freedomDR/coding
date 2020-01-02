#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    string t = a;
    for(int i = k; i < n; i++)
        t[i] = t[i-k];
    if(t < a)
    {
        for(int i = k-1; i >= 0; i--)
        {
            if(t[i] == '9') 
            {
                t[i] = '0';
            }else
            {
                ++t[i];
                break;
            }
        }
    }
    for(int i = k; i < n; i++)
        t[i] = t[i-k];
    cout << n << endl;
    cout << t << endl;
    return 0;
}

