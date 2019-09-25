#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, des_s = "";
    int sums = 0, n;
    cin >> n;
    cin >> s;
    int as = 0, bs = 0;
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(s[i] == 'a')
        {
            if(as+1-bs<2) des_s.push_back('a'),as++;
            else
            {
                sums++;
                des_s.push_back('b');
                bs++;
            }
        }
        else
        {
            if(bs+1-as<2) des_s.push_back('b'), bs++;
            else
            {
                sums++;
                des_s.push_back('a');
                as++;
            }
        }
    }
    cout << sums << endl;
    cout << des_s << endl;
    return 0;
}
