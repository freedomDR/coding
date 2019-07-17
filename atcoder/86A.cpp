#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, ans = 0;
    scanf("%d %d",&a, &b);
    if(a%2 == 0)
        ans++;
    if(b%2 == 0)
        ans++;
    if(ans == 0)
        printf("Odd\n");
    else
        printf("Even\n");
    return 0;
}
