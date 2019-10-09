#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
    vector<bool> used(10);
    while(x)
    {
        if(used[x%10]) return false;
        used[x%10] = true;
        x /= 10;
    }
    return true;
}
int main()
{
    int l, r, ans = -1;
    cin >> l >> r;
    for(int i = l; i <= r; i++)
    {
        if(check(i)) ans = i;
    }
    cout << ans << endl;
    return 0;
}
