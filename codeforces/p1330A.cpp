#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(auto &it:a) cin >> it;
        int i = 1;
        for(; i < 1000; i++)
        {
            bool find = false;
            for(auto it:a) if(it == i) find = true;
            if(!find)
            {
                if(x==0) {i--;break;}
                x--;
            }
        }
        cout << i << endl;
    }
    return 0;
}