#include <bits/stdc++.h>

int main()
{
    int n; std::cin >> n;
    std::vector<int> arr(n+1);
    int sums = 0;
    int min_odd = 1e9;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> arr[i];
        sums += arr[i];
        if(arr[i]%2) min_odd = std::min(min_odd, arr[i]); 
    }
    if(sums%2) sums -= min_odd;
    std::cout << sums << std::endl;
    return 0;
}
