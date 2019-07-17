#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin>>x;
    for(int a = 1; a <= x; a++){
        for(int b = a; b <= x; b += a){
            if(a*b > x && b/a < x){
                cout<<b<<" "<<a<<endl;
                return 0;
            }
        }
    }
    cout<<"-1\n";
    return 0;
}
