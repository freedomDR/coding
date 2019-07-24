#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> a(n);
    int sums = 0;
    for(int i = 0; i < n; i++) {cin >> a[i];sums+=a[i];}
    int temp = a[0], res = 1;
    for(int i = 1; i < n; i++) {
        if(a[i]*2 <= a[0]) {
            temp += a[i];
            a[i] = 0;
            res++;
        }
    }
    if(temp*2 <= sums){
        cout << "0" << endl;
    }else {
        cout << res << endl;
        cout << "1 ";
        for(int i = 1; i < n; i++)
            if(a[i] == 0) cout << i+1 << " ";
    }
    return 0;
}
