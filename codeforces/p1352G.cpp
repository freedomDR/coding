#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n < 4) {cout << "-1" << endl; continue;}
        deque<int> q;
        q.push_back(3);
        q.push_back(1);
        q.push_back(4);
        q.push_back(2);
        for(int i = 5; i <= n; i++) 
        {
            if(i%2==1) q.push_back(i);
            else q.push_front(i);
        }
        for(auto v:q) cout << v << " ";
        cout << endl;
    }
    return 0;
}