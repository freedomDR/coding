#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    for(auto &it:s) cin >> it;
    for(auto &it:t) cin >> it;
    for(auto &ss:s)
    {
        int sums = 0;
        for(auto &tt:t)
        {
            int p1 = 0, p2 = 0;
            while(p1 < ss.size() && p2 < tt.size())
            {
                if(ss[p1] == tt[p2]) {p1++;p2++;}
                else {p1++;}
            }
            if(p2 == tt.size()) sums++;
        }
        cout << sums << endl;
    }
    return 0;
}