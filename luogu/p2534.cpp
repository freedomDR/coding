#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <thread>

int N;
int target[17];
int t[17];

int diff()
{
    int res = 0;
    for(int i = 1; i < N; i++)
    {
        if(std::abs(t[i]-t[i-1])!=1) res++;
    }
    return res;
}

bool dfs(int step, int depth, int pre)
{
    if(depth == step)
    {
        if(diff()==0 && t[0] == 1)
        {
            /* std::cout << "**********" << std::endl; */
            /* for(int i = 0; i < N; i++) */
            /*     std::cout << t[i] << " "; */
            /* std::cout << std::endl << "**********" << std::endl; */
            return true;
        }
        else return false;
    }
    if(diff()+step>depth) return false;
    int ans = false;
    for(int i = N-1; i > 0; i--)
    {
        int l = 0, r = i;
        if(i == pre) continue;
        std::reverse(t, t+r+1);
        ans |= dfs(step+1, depth, i);
        std::reverse(t, t+r+1);
    }
    return ans;
}

void slove()
{
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> t[i];
        target[i] = t[i];
    }
    std::sort(target, target+N);
    for(int i = 0; i < N; i++)
    {
        t[i] = std::lower_bound(target, target+N, t[i])-target+1;
    }
    int depth = 0;
    while(++depth <= N*2)
    {
        if(dfs(0, depth, -1))
            break;
    }
    std::cout << depth << std::endl;
}

int main()
{
    int T = 1;
    while(T--)
    {
        slove();
    }
    return 0;
}
