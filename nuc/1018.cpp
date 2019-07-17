#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(1){
        cin>>n;
        if(n == 0)
            break;
        cout<<"the following sequence of numbers "<<n<<" will be printed :";
        while(n != 1){
            cout<<n<<" ";
            if(n%2 == 1)
                n = 3*n+1;
            else
                n /= 2;
        }
        cout<<n<<endl;
    }
    return 0;
}
