#include<bits/stdc++.h>
using namespace std;
vector<int> res(1001), base(1001), temp(1001);

void calc1(){
    for(auto & it:temp) it = 0;
    for(int i = 1; i <= 500; i++) {
        for(int j = 1; j <= 500; j++) 
            temp[i+j-1] += res[i]*base[j];
    }
    for(int i = 1; i <= 500; i++){
        temp[i+1] += temp[i]/10;
        temp[i] %= 10;
    }
    for(int i = 0; i <= 500; i++)
        res[i] =temp[i];
}

void calc2(){
    for(auto &it:temp) it = 0;
    for(int i = 1; i <= 500; i++)
        for(int j = 1; j <= 500; j++)
            temp[i+j-1] += base[i]*base[j];
    for(int i = 1; i <= 500; i++) {
        temp[i+1] += temp[i]/10;
        temp[i] %= 10;
    }
    for(int i = 0; i <= 500; i++) {
        base[i] = temp[i];
    }
}

int main(){
    int p; cin >> p;
    cout << (int)(log10(2)*p+1) << endl;
    res[1] = 1;
    base[1] = 2;
    while(p != 0) {
        if(p&1) calc1();
        p >>= 1;
        calc2();
    }
    res[1] -= 1;
    for(int i = 500; i >= 1; i--) {
        if(i != 500 && i%50 == 0) cout << endl;
        cout<< res[i];
    }
    return 0;
}
