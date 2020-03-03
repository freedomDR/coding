#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    a %= 23; b %= 233; c %= 2333;
    for(int i = 0; i*2333+c < INT_MAX; i++)
    {
        int x = i*2333+c;
        if(x%23 == a && x%233 == b) 
        {
            cout << x << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
