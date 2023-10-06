#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>

int main()
{
    int a, b; std::cin >> a >> b;
    const double PI  =3.141592653589793238463;
    double ans = std::atan(1.0)*4*(a+b)*(a+b);
    printf("%.10f\n", ans);
    return 0;
}
