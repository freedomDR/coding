#include<bits/stdc++.h>

using namespace std;

struct T
{
    int x, y;
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<T> node(k);
    for(int i = 0; i < k; i++)
    {
        cin >> node[i].x >> node[i].y;
    }   
    for(int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        node[i].x = x-node[i].x;
        node[i].y = y-node[i].y;
    }
    sort(node.begin(), node.end(), [](T &t1, T &t2){
        return (t1.x<t2.x)||(t1.x==t2.x&&t1.y<t2.y);
    });
    string ans = "";
    int x = 0, y = 0;
    for(int i = 0; i < k; i++)
    {
        int xx = node[i].x-x, yy = node[i].y-y;
        if(xx>0) ans += string(xx, 'D');
        if(xx<0) ans += string(-xx, 'U');
        if(yy>0) ans += string(yy, 'R');
        if(yy<0) ans += string(-yy, 'L');
        x = node[i].x;
        y = node[i].y;
    }
    // cout << ans << endl;
    if(ans.size() <= 2*n*m) cout << ans.size() << endl << ans << endl;
    else cout << "-1" << endl; 
    return 0;
}