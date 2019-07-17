#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int pos_int = 0, neg_int = 0, zero_int = 0, n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int a;cin>>a;
        if(a == 0) zero_int++;
        else if(a < 0) neg_int++;
        else pos_int++;
    }
    int judge = (n+1)/2;
    if(pos_int >= judge) cout<<"1"<<endl;
    else if(neg_int >= judge) cout<<"-1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}
