#include <bits/stdc++.h>

using namespace std;

int main()
{
    array<int, 3> v;
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    v[0] = a; v[1] = b; v[2] = c;
    sort(v.begin(), v.end());
    int ans = 0;
    if(v[0] + v[1] <= v[2]){ans += v[2] - v[1] - v[0] + 1; v[0] += ans;}
    if(v[2] - v[1] >= v[0]){ans += v[0] - v[2] + v[1] + 1;}
    printf("%d\n", ans);
    return 0;
}
