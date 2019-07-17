#include <bits/stdc++.h>
#define MAX 200050
using namespace std;
int n, a[MAX], b[MAX], t[MAX];
int main()
{
    cin>>n;
    n --;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    int f = 0;
    while(f <= 3){
        t[0] = f;
        int check = 1;
        for(int i = 0; i < n; i++){
            if(b[i] > a[i]){cout<<"NO"<<endl;return 0;}
            int x = 0;
            for(; x <= 3; x++){
                if((t[i]|x) == a[i] && (t[i]&x) == b[i]){t[i+1] = x;break;}
            }
            if(x == 4){check = 0;break;}
        }
        if(check) break;
        f++;
    }
    if(f == 4){cout<<"NO"<<endl;}
    else{
        cout<<"YES"<<endl;
        for(int i = 0; i <= n; i++) cout<<t[i]<<" ";
        cout<<endl;
    }
    return 0;
}
