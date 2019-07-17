#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[101], t[11];
    scanf("%s %s",s, t);
    int slen = strlen(s), tlen = strlen(t), i, j, f = 0;
    for(i = 0; i < slen; i++){
        for(j = 0; j < tlen; j++){
            if(i+j == slen || s[i+j] != t[j])
                break;
        }
        if(j == tlen){
            f = 1;
            break;
        }
    }
    if(f){
        for(i = 0; i < slen; i++){
            for(j = 0; j < tlen; j++){
                if(i+j == slen || s[i+j] != t[j])
                    break;
            }
            if(j == tlen){
                cout<<"(";
                cout<<t<<")";
                i += tlen - 1;
            }else {
                cout<<s[i];
            }
        }
        cout<<endl;
    }else {
        cout<<"Not Found"<<endl;
    }
    return 0;
}
