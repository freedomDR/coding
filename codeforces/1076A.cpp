#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int n,d;
    cin>>n>>s;
    for(d = 1; d < n; d++){
        if(s[d] < s[d-1]){
            break;
        }
    }
    s.erase(d-1, 1);
    cout<<s<<endl;
    return 0;
}
