#include <bits/stdc++.h>

using namespace std;

int main()
{
    double val, st = 2.0;
    cin>>val;
    int n = 0;
    while(val > 0){
        n++;
        val -= st;
        st = st*0.98;
    }
    cout<<n<<endl;
    return 0;
}
