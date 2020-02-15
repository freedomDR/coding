#include<bits/stdc++.h>

using namespace std;

int m, n, k, l, d, g[1010][1010], row[1010], column[1010], ansr[1010], ansc[1010]; 

bool cmp1(int i, int j)
{
    return row[i]>row[j] || (row[i]==row[j]&&i<j);
}
bool cmp2(int i, int j)
{
    return column[i]>column[j] || (column[i]==column[j]&&i<j);
}

int main()
{
    cin >> m >> n >> k >> l >> d;
    for(int i = 0; i < 1010; i++) ansr[i] = ansc[i] = i; 
    for(int i = 0; i < d; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2)
        {
            column[min(y1,y2)]++;
        }else
        {
            row[min(x1,x2)]++;
        }
    }
    sort(ansr+1, ansr+m+1, cmp1);
    sort(ansc+1, ansc+n+1, cmp2);
    vector<int> rr, cc;
    for(int i = 1; i <= k; i++ )
        rr.push_back(ansr[i]);
    for(int i = 1; i <= l; i++)
        cc.push_back(ansc[i]);
    sort(rr.begin(), rr.end());
    sort(cc.begin(), cc.end());
    for(auto &v:rr) cout << v << " ";
    cout << endl;
    for(auto &v:cc) cout << v << " ";
    cout << endl;
    return 0;
}
