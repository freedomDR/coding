#include <bits/stdc++.h>

using namespace std;

int main()
{
    double sum = 0.0,mid;
    int n = 12;
    while(n--){
        cin>>mid;
        sum += mid;
    }
    printf("$%0.2lf\n", sum/12);
    return 0;
}
