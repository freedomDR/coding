#include <bits/stdc++.h>

int main()
{
    int n; std::cin >> n;
    std::vector<int> arr(n), vis(n+2, 0);
    bool zero = 0;
    int sums = 0;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        if(arr[i] == 0)
            zero = true;
        sums += arr[i];
    }
    if(!zero||sums==0)
    {
        std::cout << "0\n";
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i]==0)
        {
            if(i>0) ans = std::max(ans, arr[i-1]);
            if(i+1<n) ans = std::max(ans, arr[i+1]);
        }
        vis[arr[i]] = 1;
    }
    for(int i = 0; i <= n+1; i++)
    {
        if(vis[i]==0)
        {
            ans = std::max(ans, i);
            break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
