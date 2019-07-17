#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, a[1010]={};
    cin>>n;
    for(int i = 0; i < n*n; i++)
    {
        int tmp;cin>>tmp;
        a[tmp]++;
    }
    vector<vector<int>> ans(n, vector<int>(n));
    int four = 1;
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){
            while(four < 1010 && a[four] < 4) four++;
            if(four == 1010) {cout<<"NO"<<endl;return 0;}
            ans[i][j] = four;ans[n-1-i][j] = four;
            ans[i][n-1-j] = four; ans[n-1-i][n-1-j] = four;
            a[four] -= 4;
        }
    }
    if(n%2){
        int one = 1;
        while(one < 1010 && a[one]%2 == 0) one++;
        if(one == 1010) {cout<<"NO"<<endl;return 0;}
        ans[n/2][n/2] = one;
        a[one] -= 1;
        int two = 1;
        for(int i = 0; i < n/2; i++)
        {
            while(two<1010 && a[two]<2) two++;
            if(two == 1010) {cout<<"NO"<<endl;return 0;}
            ans[n/2][i] = two;ans[n/2][n-1-i] = two;
            a[two] -= 2;
            while(two<1010 && a[two]<2) two++;
            if(two == 1010) {cout<<"NO"<<endl;return 0;}
            ans[i][n/2] = two;ans[n-1-i][n/2] = two;
            a[two] -= 2;
        }
    }
    cout<<"YES"<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
