#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, c; cin >> n >> c;
    vector<int> arr(n);
    for(auto &v:arr) cin >> v;

    for(auto &v:arr) cout << v << " ";
    cout << endl;
    return 0;
}
