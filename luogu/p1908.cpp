#include<bits/stdc++.h>
using namespace std;

long long mergesort(vector<int>& t, int l, int r) {
    if(l >= r) return 0;
    int mid = l + (r-l)/2;
    long long left = mergesort(t, l, mid);
    long long right =mergesort(t, mid+1, r);
    long long ans = 0ll;
    int i = l, j = mid+1;
    vector<int> temp;
    while(i <= mid && j <= r) {
        if(t[i] <= t[j]) temp.push_back(t[i++]);
        else {
            temp.push_back(t[j++]);
            ans += mid-i+1;
        }
    }
    while(i <= mid) {temp.push_back(t[i++]);}
    while(j <= r) {temp.push_back(t[j++]);}
    for(int k = l, p = 0; k <= r; k++, p++) {
        t[k] = temp[p];
    }
    return ans + left + right;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    long long ans = mergesort(t, 0, n-1);
    cout << ans << endl;
    return 0;
}
