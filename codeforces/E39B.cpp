#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b;
    cin>>a>>b;
    while(1){
        if(a == 0 || b == 0){
            break;
        }
        else if(a >= 2*b){
            long long mid = (a-2*b)/(2*b);
            a = a - mid*2*b;
            if(mid == 0)
                a = a- 2*b;
        }else if(b >= 2*a ){
            long long mid = (b-2*a)/(2*a);
            b = b - mid*2*a;
            if(mid == 0)
                b = b-2*a;
        }else{
            break;
        }
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
