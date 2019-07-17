#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, h, k;
    cin>>w>>h>>k;
    int ans = 0;
    for(int i = 0; i < k; i++){
        ans += ((w-4*i)+(h-4*i))*2 - 4;
    }
    cout<<ans<<endl;
    return 0;
}
