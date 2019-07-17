#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr(1010, 0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int v; cin >> v;
        arr[v]++;
    }
    int len = 0;
    for(int i = 0; i < 1010; i++)
    {
        if(arr[i]) len++;
    }
    cout<<len<<endl;
    for(int i = 0; i < 1010; i++)
    {
        if(arr[i]) cout<<i<<" ";
    }
    return 0;
}
