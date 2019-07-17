#include <bits/stdc++.h>
char h[19][10] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char t[20][10] = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int get_month(const char *s)
{
    int i,j;
    char b[10];
    strcpy(b,s);
    for(i = 0; i < 19; i++){
        if(strcmp(h[i], s) == 0) return i;
    }
}
int main()
{
    int n,m;
    int year[10000], day[10000], month,flag;
    int sum;
    char Month[10000][10];
    scanf("%d",&n);
    m = n;
    while(m--)
    {
        scanf("%d. %s %d",&day[m],Month[m],&year[m]);
        month = get_month(Month[m]);
        sum = year[m] * 365 + (month) * 20 + day[m];
        year[m] = sum / 260;
        flag = sum % 260;
        strcpy(Month[m],t[flag%20]);
        day[m] = flag % 13+1;
    }
    m = n;
    printf("%d\n",n);
    while(m--)
        printf("%d %s %d\n",day[m],Month[m],year[m]);
    return 0;
}
