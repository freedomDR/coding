#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin>>a[i];
    int sum = std::accumulate(a.begin(), a.end(), 0);
    int aver = sum/N, l = 0, r = N-1, ans = 0;
    while(l < r){
        if(a[l] != aver){
            a[l+1] -= aver - a[l];
            ans++;
        }
        if(a[r] != aver){
            a[r-1] -= aver - a[r];
            ans++;
        }
        l++;r--;
    }
    cout<<ans<<endl;

    return 0;
}
