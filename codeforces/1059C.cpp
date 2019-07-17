#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i*=2){
        int f = n/i;
        if(f == 3){
            printf("%d %d %d\n", i, i, i*3);
            break;
        }
        for(int j = i; j <= n; j += i*2) printf("%d ", i);
    }
    return 0;
}
