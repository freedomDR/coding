#include <bits/stdc++.h>

using namespace std;

int a, n, ans[1000005];
int main()
{
    ans[1] = 0;
    ans[2] = 1;
    for(int i = 3; i < 1000005; i++){
        ans[i] = ans[i-1] + ans[i-2];
        if(ans[i] > 10000000) ans[i] %= 10000000;
    }
    cin>>n;
    while(n--){
        cin>>a;
        cout<<ans[a]<<endl;
    }
    return 0;
}
