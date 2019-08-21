#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    int smin = n-(l-1);
    for(int i = 1, t = 2; i < l; i++) {
        smin += t; t *= 2;
    }
    int smax = 0;
    for(int i = 0, t = 1; i < r; i++) {
        smax += t;
        if(i == r-1) {smax += (n-r)*t;}
        t *= 2;
    }
    cout << smin << " " << smax << endl;
    return 0;
}
