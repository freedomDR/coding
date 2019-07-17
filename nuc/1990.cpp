#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x, y, x1, y1, r;
    double a, b, c, d, e;
    cin>>x>>y>>x1>>y1>>r;
    cin>>a>>b>>c>>d>>e;
    double live = 100.0/e;
    double need = (sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y)) - r);
    if(need <= 0){
        cout<<"0.000"<<endl;
        return 0;
    }
    double mid = a*c/b;
    if(need <= mid){
        need = need/c;
    }else{
        need = (a/b) + (need-mid)/d;
    }
    if(need <= live){
        printf("%0.3lf\n", need);
    }
    else
        printf("GG\n");
    return 0;
}
