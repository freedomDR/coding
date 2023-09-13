#include <bits/stdc++.h>

int main()
{
    int t; std::cin >> t;
    while(t--)
    {
        int n, k; std::cin >> n >> k;
        std::vector<int> b(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> b[i];
            b[i]--;
        }
        if(k == 1)
        {
            bool ans = true;
            for(int i = 0; i < n; i++)
            {
                if(i!=b[i])
                {
                    ans = false;
                    break;
                }
            }
            std::cout << (ans?"YES":"NO") << std::endl;
        }
        else
        {
            std::vector<int> vis(n, -1);
            bool ans = true;
            for(int i = 0; i < n; i++)
            {
                int j = i;
                while(vis[j] == -1)
                {
                    vis[j] = i;
                    j = b[j];
                }
                if(vis[j] == i)
                {
                    int len = 0;
                    int x = j;
                    do 
                    {
                        len++;
                        x = b[x];
                    }while(x != j);
                    if(len != k)
                    {
                        ans = false;
                        break;
                    }
                }
            }
            std::cout << (ans?"YES":"NO") << std::endl;
        }
    }
    return 0;
}
