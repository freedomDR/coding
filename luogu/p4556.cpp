#include<iostream>
#include<string>
#include<vector>

using namespace std;

string s;
vector<int> d, ll, rr; 
void manacher()
{
    string new_s = "#";
    for(auto c:s)
    {
        new_s.push_back(c);
        new_s.push_back('#');
    }
    d.resize(new_s.size());
    int l = 0, r = -1; 
    for(int i = 0; i < new_s.size(); i++)
    {
        int j = i>r?1:min(d[r-i+l], r-i+1);
        while(i-j>=0&&i+j<new_s.size()&&new_s[i+j]==new_s[i-j])
            j++;
        d[i] = j--;
        if(i+j>r)
        {
            r = i+j;
            l = i-j;
        }
        // #a#b#c#b#b#c
        // 112214123211    
        // d[i]+i-1-1 
        ll[i+d[i]]
    }
}

int main()
{
    cin >> s;
    return 0; 
}