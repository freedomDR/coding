#include <bits/stdc++.h>

using namespace std;

int main()
{
        long long a1, a2, l1, l2, c, x, y; 
        cin>>a1>>l1>>a2>>l2;
        cin>>c>>x>>y;
        for(int i = 0; i <= c; i++){
                long long l11 = l1 + (c-i)*y;
                long long a11 = a1 + x*i;
                long long tmp1 = (l11 + a2 - 1)/a2;
                long long tmp2 = (l2 + a11 - 1)/a11;
                if(tmp1 >= tmp2){
                        cout<<"1"<<endl;
                        return 0;
                }
        }
        cout<<"0"<<endl;
        return 0;
}
