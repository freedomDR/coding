#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> odd(n-n/2 + 1), even(n/2 + 1);
    for(int i = 1, oi = 1, ei = 1; i <= n; i++)
    {
         int a;cin>>a;
         if(i%2 == 0) {even[ei] += even[ei-1]+a; ei++;}
         else{odd[oi] += odd[oi-1]+a;oi++;}
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(i%2 == 0) {
            long long e1 = even[i/2-1], e2 = even[n/2]-even[i/2]; // 偶数
            long long o1 = odd[i/2], o2 = odd[n-n/2]-odd[i/2];//奇数
            if(e1+o2 == e2+o1) ans++;
        }
        else {
            long long e1 = even[i/2], e2 = even[n/2]-even[i/2]; // 偶数
            long long o1 = odd[i/2], o2 = odd[n-n/2]-odd[i/2+1];//奇数
            if(e1+o2 == e2+o1) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
