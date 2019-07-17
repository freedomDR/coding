#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> apple(10);
    for(int i = 0; i < 10; i++) cin>>apple[i];
    int ans = 0, height;
    cin >> height;
    for(int i = 0; i < 10; i++)
        if(apple[i] <= height+30) ans++;
    cout<<ans<<endl;
    return 0;
}
