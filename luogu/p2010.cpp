#include <bits/stdc++.h>

using namespace std;

int m[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(int argc, char *argv[])
{
    int l, r, ans = 0;
    std::cin >> l >> r;
    for (int i = 1; i <= 12; i++) 
    {
        for (int j = 0; j <= m[i]; j++)
        {
            int t = j + i*100 + (i/10 + (i%10)*10)*10000 + (j/10 + (j%10)*10)*1000000;
            if(t >= l && t <= r)
                ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
