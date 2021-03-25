#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int len = s.length();
    vector<int> p(len, 0);
    for(int i = 1; i < len; i++)
    {
        int j = p[i-1];
        while(j>0&&s[i]!=s[j]) j = p[j-1];
        if(s[i]==s[j]) j++;
        p[i] = j;
    }
    int retLen = len-p[len-1];
    for(int i = 1; i < k; i++)
    {
        for(int j = 0; j < retLen; j++)
            cout << s[j];
    }
    cout << s << endl;
    return 0;
}