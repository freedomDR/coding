#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x, n, m;
        cin >> x >> n >> m;
        while(x > 0)
        {
            int t = x-(x/2+10);
            if(t>0&&n>0)
            {
                x = x/2+10;
                n--;
            }else
            {
                if(m>0) {x-=10;m--;}
                else break;
            }
        }
        cout << (x<=0?"YES":"NO") << endl;
    }
    return 0;
}