#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        int equal_c = 1;
        while(s[i] == s[i-1]){
            i++;
            equal_c++;
        }
        ans += equal_c/2;
    }
    cout<<ans<<endl;
    return 0;
}
