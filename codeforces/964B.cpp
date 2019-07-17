#include <bits/stdc++.h>

using namespace std;
int t[1010];
int main()
{
    int n,a,b,c,T;
    cin>>n>>a>>b>>c>>T;
    int sum = 0;
    if(b>=c){
        while(n--){
            int mid;
            cin>>mid;
            if(mid <= T)
                sum += a;
        }
    }else{
        while(n--){
            int mid;
            cin>>mid;
            if(mid <= T) {
                sum += a;
                sum += (T-mid)*(c-b);
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
