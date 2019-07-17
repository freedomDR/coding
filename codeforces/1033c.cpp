#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> a(n), pos(n);
    for(int i = 0; i < n; i++){
        cin>>a[i]; a[i]--; pos[a[i]] = i;
    }
    string win(n, '?');
    for(int i = n-1; i >= 0; i--){
        int p = pos[i];
        win[p] = 'B';
        int j = p;
        while(true){
            j -= (i+1);
            if(j < 0) break;
            if(win[j] == 'B'){
                win[p] = 'A';break;
            }
        }
        j = p;
        while(true){
            j += (i+1);
            if(j >= n) break;
            if(win[j] == 'B'){
                win[p] = 'A';break;
            }
        }
    }
    cout<<win<<endl;
    return 0;
}
