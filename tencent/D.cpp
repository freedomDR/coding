#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    priority_queue<int, vector<int>, greater<int>> p;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        p.push(v);
    }
    int c = 0;
    while(k--)
    {
        if(p.empty()) {cout << "0" << endl;continue;}
        if(p.top() == c) {p.pop();k++;continue;}
        cout << (p.top()-c) << endl;
        c += (p.top()-c);
        p.pop();
    }
}
