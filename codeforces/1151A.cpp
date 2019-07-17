#include <bits/stdc++.h>

using namespace std;

int main()
{
    int res = INT_MAX, n;
    string s, pattern = "ACTG";
    cin>>n>>s;
    for(int i = 0; i <= s.size() - 4; i++) {
        int v = 0;
        for(int j = 0; j < 4; j++){
            int l1 = 0, l2 = 0;
            char c = s[i+j];
            while(c != pattern[j]) {
                if(c == 'Z') c = 'A';
                else c++;
                l1++;
            }
            c = s[i+j];
            while(c != pattern[j]) {
                if(c == 'A') c = 'Z';
                else c--;
                l2++;
            }
            v += min(l1, l2);
        }
        res = min(res, v);
    }
    cout<<res<<endl;
    return 0;
}
