#include<iostream>

using namespace std;

int a[105], b[105], n, t, c[105];

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        int s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i]>b[i]) s1 += a[i]-b[i];
            else s2 += b[i]-a[i]; 
            c[i] = a[i]-b[i];
        }
        //cout << s1 << " " << s2 << endl;
        if(s1 != s2)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << s1 << endl;
        int l1 = 0, l2 = 0;
        while(true)
        {
            while(l1 < n && c[l1]<=0) l1++;
            while(l2 < n && c[l2]>=0) l2++;
            //cout << l1 << " " << l2 << endl;
            if(l1 == n || l2 == n) break;
            for(int pos = 0; pos < min(c[l1], -c[l2]); pos++)
            {
                cout << l1+1 << " " << l2+1 << endl;
                c[l1]--;
                c[l2]++;
            }
        }
    }
    return 0;
}