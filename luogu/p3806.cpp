#include<iostream>
#include<vector>
#include<string>

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
    vector<int> d(new_s.size());
    int l = 0, r = -1;
    for(int i = 0; i < new_s.size(); i++)
    {
        int j = i>r?1:min(d[r-i+l], r-i+1);
        while(i-j>=0&&i+j<new_s.size()&&new_s[i-j]==new_s[i+j])
            j++;
        d[i] = j--;
        if(i+j>r)
        {
            l = i-j;
            r = i+j;
        }
    }
    //cout << new_s << endl;
    //for(auto v:d) cout << v;
    //cout << endl;
    int ans = 1;
    for(int i = 1; i < d.size(); i += 2)
    {
        int d1 = d[i]/2;
        int d2 = (d[i+1]-1)/2;
        ans = max(ans, max(d1*2-1, d2*2));
    }
    cout << ans << endl;
}

int main()
{
    cin >> s;
    manacher();
    return 0;
}