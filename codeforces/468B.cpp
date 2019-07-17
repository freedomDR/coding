#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(a-1<=1 && n-b<=1){
        cout<<"Final!"<<endl;
    }else{
        int ans = abs(a-b)/2 + abs(a-b)%2;
        cout<<ans<<endl;
    }
    return 0;
}
