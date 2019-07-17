#include <bits/stdc++.h>

using namespace std;
char s[100050];

int main()
{
    scanf("%s",s);
    int pos = 1;
    for(int i = 0; s[i] != '\0' && pos <= 26; i++){
        if(s[i] - 'a' + 1 <= pos){
            s[i] = 'a'+pos-1;
            pos++;
        }
    }
    if(pos == 27){
        printf("%s\n", s);
    }else{
        printf("-1\n");
    }
    return 0;
}
