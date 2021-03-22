#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

void kmp(string & s1, string & s2)
{
    string new_s = s2+"#"+s1;
    int len = new_s.size();
    int len1 = s1.size();
    int len2 = s2.size();
    vector<int> d(len, 0);
    for(int i = 1; i < len; i++)
    {
        int j = d[i-1];
        while(j>0 && new_s[i]!=new_s[j]) j = d[j-1];
        if(new_s[j] == new_s[i]) j++;
        d[i] = j; 
    }   
    for(int i = len2+1; i < len; i++)
    {
        if(d[i] == len2)
            cout << i-2*len2+1 << endl;
    } 
    for(int i = 0; i < len2; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    kmp(s1, s2);
    return 0;
}