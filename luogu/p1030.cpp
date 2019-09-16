#include<bits/stdc++.h>
using namespace std;

void walk(string s1, string s2)
{
    if(s1.length() == 1)
    {
        cout << s1;
        return;
    }
    cout << s2.back();
    int length = 0;
    for(auto &it:s1)
    {
        if(it == s2.back()) break;
        length++;
    }
    if(length != 0)
        walk(s1.substr(0, length), s2.substr(0, length));
    if(length < s1.length()-1)
        walk(s1.substr(length+1), s2.substr(length, s2.length()-1-length));
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    walk(s1, s2);
    return 0;
}
