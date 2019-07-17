#include <bits/stdc++.h>

using namespace std;
int a[100];
inline int lowbit(int x){
    return x&(-x);
}

void add(int p, int s){
    for(int i = p; i < 100; i += lowbit(i)){
        a[i] += s;
    }
}

int sum(int pos){
    int ans = 0;
    for(; pos > 0; pos -= lowbit(pos)){
        ans += a[pos];
    }
    return ans;
}

int main()
{
    for(int i = 1; i < 100; i++){
        add(i, i);
    }
    for(int i = 1; i < 100; i++){
        cout<<sum(i)<<endl;
    }
    return 0;
}
