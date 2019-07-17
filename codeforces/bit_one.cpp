#include <bits/stdc++.h>
using namespace std;
int main()
{ 
    int n, res = 0;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    //解法1
    for(int i = 0; i < 32; i++){
        int x = (1<<i);
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(a[j]&x) sum++;
        }
        if(sum%3) res += x;
    }
    cout<<res<<endl;
    return 0;
}
