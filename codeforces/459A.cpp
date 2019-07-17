#include <bits/stdc++.h>

using namespace std;

int f[1000];

int main()
{
    memset(f,0,sizeof(f));
    int a,b,c, n;
    cin>>n;
    a = b = 1;
    f[1] = 1;
    for(;b <= 1000;){
        c = a+b;
        f[c] = 1;
        a = b;
        b = c;
    }
    for(int i = 1; i <= n; i++){
        if(f[i])
            cout<<"O";
        else
            cout<<"o";
    }
    cout<<endl;
    return 0;
}
