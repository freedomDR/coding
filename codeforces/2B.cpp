#include <bits/stdc++.h>

using namespace std;
int d2[1010][1010], d5[1010][1010], a2[1010][1010], a5[1010][1010];
bool have_zero = false;
int zero_i,zero_j;
int n, mid;
void walk(int x, int y, int d[][1010])
{
    if(x == n-1 && y == n-1)
        return;
    if(d[x+1][y] < d[x][y+1]){
        cout<<"D";
        walk(x+1, y, d);
    }
    else{
        cout<<"R";
        walk(x, y+1, d);
    }
}
int main()
{
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>mid;
            if(mid == 0) have_zero = true, zero_i = i, zero_j = j, mid = 10;
            while(mid % 5 == 0) a5[i][j]++, mid /= 5;
            while(mid % 2 == 0) a2[i][j]++, mid /= 2;
        }
    }
    d2[0][0] = a2[0][0];
    d5[0][0] = a5[0][0];
    for(int i = 1; i < n; i++){
        d2[0][i] += a2[0][i-1], d2[i][0] += a2[i-1][0];
        d5[0][i] += a5[0][i-1], d5[i][0] += a5[i-1][0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            d2[i][j] = min(d2[i-1][j], d2[i][j-1]) + a2[i][j];
            d5[i][j] = min(d5[i-1][j], d5[i][j-1]) + a5[i][j];
        }
    }
    int ans = min(d2[n-1][n-1], d5[n-1][n-1]);
    cout<<ans<<endl;
    if(have_zero && ans > 1){
        for(int i = 0; i <= zero_i; i++) cout<<"D";
        for(int j = 0; j < n; j++) cout<<"R";
        for(int i = zero_j; i < n; i++) cout<<"D";
    }else{
        cout<<d2[n-1][n-1]<<d5[n-1][n-1]<<endl;
        //if(d2[n-1][n-1] < d5[n-1][n-1]) walk(0, 0, d5);
        //else walk(0, 0, d2);
        cout<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<d2[i][j]<<" ";
            }
        cout<<endl;
        }
    }
    return 0;
}
