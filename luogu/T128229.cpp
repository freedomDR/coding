#include<bits/stdc++.h>

using namespace std;
long long v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if(k%2==1)
    {
    }else
    {
        set<long long> s;
        for(int i = 0; i < n; i++)
        {
            cin >> v;
            if(s.find(v) == s.end()) s.insert(v);
            else s.erase(v);
        }
        cout << *(s.begin()) << endl;
    }
    return 0;
}