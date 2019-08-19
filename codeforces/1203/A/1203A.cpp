#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q, n;
    cin >> q;
    while(q--) {
        cin >> n;
        int ok = false;
        vector<int> a(n);
        int st = -1;
        for(int i = 0; i < n; i++) 
        {
            cin >> a[i];
            if(a[i] == 1) st = i;    
        }
        int j = st+1;
        for(int i = 1; i < n; i++, j++) {
            if(a[j%n] != a[(j-1)%n]+1) break;
        }
        if(j == st+n) ok = true;
        j = st-1;
        for(int i = 1; i < n; i++, j--) {
            if(a[(j+n)%n] != a[(j+n+1)%n]+1) break;
        }
        if(j == st-n) ok = true;
        cout << (ok?"YES":"NO") << endl;
            
    }
    return 0;
}

