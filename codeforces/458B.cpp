#include <bits/stdc++.h>

using namespace std;

int n, a[100005], mid;
int main()
{
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>mid;
        a[mid]++;
    }
    for(int i = 0; i <= 1e5; i++){
        if(a[i]%2 == 1){
            cout<<"Conan"<<endl;
            return 0;
        }
    }
    cout<<"Agasa"<<endl;
    return 0;
}
