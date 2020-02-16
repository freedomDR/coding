#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a = 0, b, sums = 0, n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> b;
        if(b > a) sums += b-a;
        a = b;
    }
    cout << sums << endl;
    return 0;
}
