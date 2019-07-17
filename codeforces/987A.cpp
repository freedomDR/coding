#include <bits/stdc++.h>

using namespace std;
string s[6] = {"purple","green","blue","orange","red","yellow"};
string ss[6] = {"Power","Time","Space","Soul","Reality","Mind"};
int main()
{
    int n;
    string mid[6];
    cin>>n;
    for(int i =0; i < n ; i++) cin>>mid[i];
    cout<<(6-n)<<endl;
    for(int i = 0; i < 6; i++){
        int j = 0;
        for(; j < n; j++){
            if(mid[j] == s[i])
                break;
        }
        if(j == n) cout<<ss[i]<<endl;
    }
    return 0;
}
