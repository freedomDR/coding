#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> used(N);
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> used[i];
    }
    while(m--) {
        next_permutation(used.begin(), used.begin()+n);
    }
    for(int i = 0; i < n; i++) cout<<used[i]<<" ";
    cout<<endl;
    return 0;
}
