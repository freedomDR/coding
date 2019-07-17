#include <bits/stdc++.h>

using namespace std;
int v[26];
int main()
{
    int t;
    scanf("%d", &t);
    scanf(" ");
    for(int i = 0; i < t; i++){
        char tmp;
        scanf("%c", &tmp);
        v[tmp-'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(v[i] != 0){
            for(int j = 0; j < v[i]; j++)
            printf("%c", 'a'+i);
        }
    }
    printf("\n");
    return 0;
}
