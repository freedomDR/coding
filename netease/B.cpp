#include<bits/stdc++.h>
using namespace std;
int a[1100];
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        int pos = 0;
        while(pos < n)
        {
            int val = 0, next = -1, max_pos = pos+1, res = 1;
            for(int i = 1; i <= k && pos+i < n; i++)
            {
                if(a[pos+i]<=a[pos] && val < a[pos+i])
                {
                    val = a[pos+i];
                    next = pos+i;
                }
                if(a[max_pos] <= a[pos+i]) max_pos = pos+i;
            }
            if(next != -1) {pos=next;}
            else
            {
                if(res == 0) break;
                else
                {
                    res = 0;
                    pos = max_pos;
                }
            }
            cout << pos << endl;
        }
        cout << (pos==n?"YES":"NO") << endl;
    }
    return 0;
}
