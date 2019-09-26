#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "";
    bool ok = true;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(i%2 == 1 && s[i] == 'R') ok = false;
        if(i%2 == 0 && s[i] == 'L') ok = false;
    }
    cout << (ok?"Yes":"No") << endl;
}
