#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, k;
    cin>>n>>m>>k;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    nth_element(a.begin(), a.begin()+m*k, a.end(), greater<pair<int, int>>());
    sort(a.begin(), a.begin()+m*k, [](pair<int, int> a1, pair<int, int> a2){return a1.second < a2.second;});
    long long sum = 0;
    for_each(a.begin(), a.begin()+m*k, [&sum](pair<int, int> i){ sum += i.first;});
    cout<<sum<<endl;
    vector<int> ans(k-1);
    for(int i = 0; i < k-1; i++)
        ans[i] = a[(i+1)*m-1].second;

    for(auto i:ans)
        cout<<i+1<<" ";
    return 0;
}
