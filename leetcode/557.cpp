#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s)
{
    auto first = s.begin();
    for(auto i = s.begin(); i != s.end(); i++)
    {
        if(*i == ' ')
        {
            reverse(first, i);
            first = i + 1;
        }
    }
    reverse(first, s.end());
    return s;
}

int main()
{
    /* ios::sync_with_stdio(false);cin.tie(0); */
    string s;
    cin.getline(s);
    cout<<s<<endl;
    string ans = reverseWords(s);
    cout<<ans<<endl;
    return 0;
}
