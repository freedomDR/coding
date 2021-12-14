#include<bits/stdc++.h>

using namespace std;
int n, m; 
vector<int> arr(1e6+5);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m; 
    arr.resize(n);
    for(auto &v:arr)
        cin >> v;
    deque<int> di, da;
    vector<int> mi, ma;
    for(int i = 0; i < n; i++)
    {
        while(!da.empty() && da.front() <= i-m) da.pop_front();
        while(!di.empty() && di.front() <= i-m) di.pop_front();
        while(!da.empty() && arr[da.back()] >= arr[i])
            da.pop_back();
        while(!di.empty() && arr[di.back()] <= arr[i])
            di.pop_back();
        da.push_back(i);
        di.push_back(i);
        if(i >= m-1)
        {
            mi.push_back(da.front());
            ma.push_back(di.front());
        }
    }
    for(auto &v:mi)
        cout << arr[v] << " ";
    cout << endl;
    for(auto &v:ma)
        cout << arr[v] << " ";
    cout << endl;
    return 0;
}
