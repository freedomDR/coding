#include <bits/stdc++.h>

const float g = 9.8;

int main()
{
    float ans, t;
    while(1)
    {
        scanf("%f",&t);
        if(t == 0.0)
            break;
        t -= 1;
        if(t <= 2)
            t = t * 5;
        else
            t = 10 + (t - 2) * 3;
        t += 1.75;
        ans = sqrt(t*2/g);
        printf("%0.3f\n",ans);
    }
    return 0;
}
