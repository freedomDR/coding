#include <bits/stdc++.h>

using namespace std;
vector<int> a;
int main()
{
    int mid;
    for(int i = 0; i < 4; i++){
        cin>>mid;
        a.push_back(mid);
    }
    sort(a.begin(), a.end());
    for(int i = 3; i >= 0; i--){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
