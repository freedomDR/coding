#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool check(int length)
{
    map<string, int> m;
    for(int i = 0; i+length <= n; i++)
    {
        string tmp = s.substr(i, length);
        if(m[tmp])
        {
            if(i+1-m[tmp]>=length) return true;
        }
        else
        {
            m[tmp] = i+1;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    cin >> s;
    int l = 0, r = n;
    while(l <= r)
    {
        int mid = (l+r)>>1;
        if(check(mid)) l = mid+1;
        else r = mid-1;
    }
    cout << r << endl;
}
