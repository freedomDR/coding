#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i = n; i >= 1; i--)
        {
            for(int j = i; j >= 1; j--)
                cout << "*";
            cout << endl;
        }
    }
    return 0;
}