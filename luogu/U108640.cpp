#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool find = false;
        for(int i = 1; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                int j = n/i;
                int need = n-(i+j);
                if((n-2-need)%2==0)
                {
                    cout << "YES" << endl;
                    map<int, int> mp;
                    mp[i]++;
                    mp[j]++;
                    mp[1] += need+(n-2-need)/2;
                    if(n-2-need!=0) mp[-1] += (n-2-need)/2;
                    cout << mp.size() << endl;
                    for(auto &it:mp)
                        cout << it.second << " " << it.first << endl;
                    find = true;
                    break;
                }
            }
        }
        if(!find) cout << "NO" << endl;
    }
    return 0;
}