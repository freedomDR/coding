#include <bits/stdc++.h>

using namespace std;

int a[10];
int main()
{
    int n, pos;
    cin>>n;
    for(int i = 0; i < 10; i++)
        cin>>a[i];
    pos = abs(n)%10;
    if(n < 0){
        for(int i = pos; i < 10; i++)
            cout<<a[i]<<" ";
        for(int i = 0; i < pos; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }else{
        for(int i = 10 - pos; i < 10; i++)
            cout<<a[i]<<" ";
        for(int i = 0; i < 10 - pos; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
