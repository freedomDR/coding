#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n==1)
        {
            cout << "-1" << endl;
            continue;
        }
        if(n==2)
        {
            cout << "23" << endl;
            continue;
        }
        string ans = "";
        if((n-1)%3==0) ans = string(n-2, '2')+string(2, '3');
        else ans = string(n-1, '2')+string(1, '3');
        cout << ans << endl;
    }
    return 0;
}