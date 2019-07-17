#include <bits/stdc++.h>

using namespace std;

int reverse_int(char *s){
    int len = strlen(s);
    char ss[10];
    int i = 0, j = len-1;
    while(i <= j){
        ss[i] = s[j];
        ss[j] = s[i];
        i++;
        j--;
    }
    ss[len] = '\0';
    int ans = atoi(ss);
    return ans;
}

int main()
{
    int n, nn;
    char s[10];
    cin>>n;
    while(n--){
        memset(s, 0, sizeof(s));
        scanf("%s", s);
        nn = atoi(s);
        nn += reverse_int(s);
        sprintf(s,"%d",nn);
        if(nn == reverse_int(s))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
