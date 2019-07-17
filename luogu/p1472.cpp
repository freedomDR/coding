#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> arr;
    while(true)
    {
        int v;cin>>v;
        if(v == 0) break;
        arr.push(v);
    }
    while(!arr.empty())
    {
        cout<<arr.top()<<" ";
        arr.pop();
    }
    return 0;
}
