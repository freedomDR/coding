#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
    cin >> n; 
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end());
    vector<int> q;
    for(int i = 0; i < n; i++)
    {
        int v = arr[i].second;
        if(q.empty()||v>q.back()) {q.push_back(v);}
        else
        {
            *lower_bound(q.begin(), q.end(), v) = v;   
        }
    }
    cout << q.size() << endl;
    return 0;
}