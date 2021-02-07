#include<iostream>
#include<string>
#include<vector>

using namespace std;
string s;

void manacher()
{
    string new_s = "#";
    for(auto c:s) 
    {
        new_s.push_back(c);
        new_s.push_back('#');
    }
    cout << new_s << endl;
    vector<int> d(new_s.size());
    int l = 0, r = -1; 
    for(int i = 0; i < d.size(); i++)
    {
        int j = i>r?1:min(d[r-i+l],r-i+1);
        while(i-j>=0&&i+j<d.size()&&new_s[i-j]==new_s[i+j]) j++;
        d[i] = j--;
        if(i+j>r)
        {
            l = i-j;
            r = i+j;
        }
    }
    for(auto v:d) cout << v << " ";
    cout << endl;

}

int main()
{
    cin >> s;
    manacher();
    return 0;
}