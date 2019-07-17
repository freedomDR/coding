#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[4], b[4];
    scanf("%s %s",a,b);
    double mid = atof(strcat(a,b));
    if(pow(int(sqrt(mid)), 2) == mid)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
