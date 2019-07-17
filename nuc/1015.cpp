#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans,n;
    string s;
    scanf("%d", &n);
    while(n--) {
        cin>>s;
        while(s.length() > 1) {
            ans = 0;
            for(int i = 0; i < s.length(); i++) {
                ans += (s[i] - '0');
            }
            s = to_string(ans);
        }
        cout<<s<<endl;
    }
    return 0;
}
