#include<bits/stdc++.h>
using namespace std;
const int N = 10100;
int fa[N];

int fd(int x)
{
    if(x == fa[x]) return x;
    else return fa[x]=fd(fa[x]);
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    for(int i = 0; i < m; i++)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if(opt == 1)
        {
            fa[fd(x)] = fd(y);
        }
        else
        {
            std::cout << (fd(x)==fd(y)?"Y":"N") << std::endl;
        }
    }

}
