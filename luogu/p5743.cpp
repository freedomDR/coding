#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    int v = 1;
    n--;
    while(n--) v = (v+1)*2;
    cout << v << endl;
    return 0;
}
