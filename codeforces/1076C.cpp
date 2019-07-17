#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, d;
    cin>>t;
    while(t--){
        cin>>d;
        double dd = d*d-4*d;
        if(dd < 0){
            cout<<"N"<<endl;
        }else{
            double ddd = (double)sqrt(dd);
            printf("Y %.12f %.12f\n",(d+ddd)/2, (d-ddd)/2);
        }
    }
    return 0;
}
