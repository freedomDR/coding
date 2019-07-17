#include <bits/stdc++.h>

using namespace std;

int m1, m2, m3, m4, n, a[2005];

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++){
        if(a[i] == 1) m1++, m3 = max(m2, m3)+1;
        else m2 = max(m2, m1)+1, m4 = max(m3, m4)+1;
    }
    cout<<max(m3, m4)<<endl;
    return 0;
}
