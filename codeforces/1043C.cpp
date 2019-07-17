#include <bits/stdc++.h>

using namespace std;
char s[1050];
int ans[1050];

int main()
{
    cin>>s;
    for(int i = 1; i < strlen(s); i++){
        int check = 0;
        if(s[i] == 'a'){
            ans[i-1] ^= 1;
            ans[i] = 1;
        }    
    }
    for(int i = 0; i < strlen(s); i++) cout<<ans[i]<<" ";
    return 0;
}
