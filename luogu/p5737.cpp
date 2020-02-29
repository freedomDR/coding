#include<bits/stdc++.h>

using namespace std;

int x, y;

bool check(int v)
{
    return (v%400==0)||(v%100&&v%4==0);
}

int main()
{
    cin >> x >> y;
    int cnt = 0;
    for(int j = x; j <= y; j++)
    {
        if(check(j)) cnt++;
    }
    cout << cnt << endl;
    for(int j = x; j <= y; j++)
    {
        if(check(j)) cout << j << " ";
    }
    return 0;
}
