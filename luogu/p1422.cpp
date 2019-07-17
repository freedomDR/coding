#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v;
    cin>>v;
    double ans = 0;
    if(v <= 150) ans = v*0.4463;
    else if(v<=400) ans = (v-150)*0.4663 + 150*0.4463;
    else ans = 150*0.4463+250*0.4663+(v-400)*0.5663;
    printf("%0.1lf\n", ans);
    return 0;
}
