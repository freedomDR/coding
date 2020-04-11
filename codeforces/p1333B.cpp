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
        vector<int> a1(n), a2(n);
        for(auto &it:a1) cin >> it;
        for(auto &it:a2) cin >> it;
        bool can = true;
        int pos = 0;
        if(a1[pos] != a2[pos]) can = false;
        pos++;
        vector<int> tmp;
        bool postive = false, neg = false;
        if(a1[0] == 1) postive = true;
        if(a1[0] == -1) neg = true;
        while(can)
        {
            if(a1[pos-1] == 1) postive = true;
            if(a1[pos-1] == -1) neg = true;
            if(pos == n) break;
            if(a1[pos]>a2[pos])
            {
                if(!neg) can = false;
            } else if(a1[pos]<a2[pos])
            {
                if(!postive) can = false;
            }
            pos++;
        }
        cout << (can?"YES":"NO") << endl;
    }
    return 0;
}