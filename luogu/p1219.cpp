#include <bits/stdc++.h>
/*
 *关键check数组，对角线的表示方法(找规律)
 *
 *
 */
using namespace std;

int n, sum, check[3][28], ans[14];
void dfs(int len)
{
    if(len > n)
    {
        sum++;
        if(sum <= 3)
        {
            for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!check[0][i] && !check[1][len+i] &&  !check[2][len-i+n])
        {
            ans[len] = i;
            check[0][i]=1;check[1][len+i]=1;check[2][len-i+n]=1;
            dfs(len+1);
            check[0][i]=0;check[1][len+i]=0;check[2][len-i+n]=0;
            ans[len] = 0;
        }
    }
}

int main()
{
    cin>>n;
    dfs(1);
    cout << sum <<endl;
    return 0;
}
