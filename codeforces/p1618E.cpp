#include<bits/stdc++.h>

using namespace std;

// a1, a2, b3
// b1 = a1 + 3*a2 + 2*a3
// b2 =  2*a1 + a2 + 3*a3
// b3 = 3*a1 + 2*a2 + a3
//
// bi = i*a1 + ... + 2*a(i-1) + ai + n*a(i+1) + ... + (i+1)*an


// b1+b2+b3+...+bn
// (n*(n+1))/2  * (a1+a2+a3+...) == b1+b2+b3+...
// a1 
// a2 b2-b1=a1+a2+a3-3*a2=S-3*a2


// a1, a2, b3, b4, b5, b6, b7
// b1 = a1 + 7*a2 + 6*a3 + 5*a4 + 4*a5 + 3*a6 + 2*a7
// b2 = 2*a1 + a2 + 7*a3 + 6*a5 + 5*a4 + 4*a3 + 3*a2 + 2*a1
// b3 = 3*a1 + 2*a2 + a3

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n; 
        vector<long long> b(n);
        for(auto &v:b) 
        {
            cin >> v;
        }
        // 0ll-long long 0l-long !!!!!!!!!!!!!!!!!!!!!!!!
        long long sums = std::accumulate(b.begin(), b.end(), 0ll);
        long long d = 1ll*n*(n+1)/2;
        if(sums%d!=0)
        {
            cout << "NO" << endl;
            continue;
        }
        long long s = sums/d;
        vector<long long> ans;
        for(int i = 0; i < n; i++)
        {
            long long tmp = s+(b[(i-1+n)%n]-b[i]);
            if(tmp <= 0 || tmp%n != 0)
                break;
            ans.push_back(tmp/n);
        }
        if(int(ans.size()) != n) {cout << "NO" << endl; continue;}
        cout << "YES" << endl;
        for(auto &v:ans) cout << v << " ";
        cout << endl;
    }
    return 0;
}
