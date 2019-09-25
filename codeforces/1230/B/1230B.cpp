#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    if(k == 0) cout << s << endl;
    else if(k == 1 && s.size() == 1) cout << "0" << endl;
    else
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(k > 0)
            {
                if(i == 0 && s[i] != '1') {cout << "1";k--;}
                else if(i > 0 && s[i] != '0') {cout << "0";k--;}
                else 
                {
                    cout << s[i];
                }
            }
            else
            {
                cout << s[i];
            }
        }
    }
    return 0;
}

