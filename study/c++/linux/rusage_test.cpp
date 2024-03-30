#include <bits/stdc++.h>
#include <memory>
#include <thread>
#include <vector>
#include <sys/resource.h>

void testThreadCost(int sz)
{
    rusage r1, r2;
    getrusage(RUSAGE_THREAD, &r1);
    std::vector<std::thread> ts;
    auto func = []()
    {
        for(int i = 0, j = 0; i < 100000000; i++)
        {
            j++;
        }
    };
    for(int i = 0; i < sz; i++)
    {
        ts.emplace_back(func);
    }
    for(int i = 0; i < sz; i++)
    {
        ts[i].join();
    }
    getrusage(RUSAGE_THREAD, &r2);
    auto v1 = (r2.ru_utime.tv_sec * 1000000000 + r2.ru_utime.tv_usec*1000) - (r1.ru_utime.tv_sec * 1000000000 + r1.ru_utime.tv_usec*1000);
    auto v2 = (r2.ru_stime.tv_sec * 1000000000 + r2.ru_stime.tv_usec*1000) - (r1.ru_stime.tv_sec * 1000000000 + r1.ru_stime.tv_usec*1000);
    std::cout << "v: "  << v1+v2 << std::endl; 
}

int main()
{
    testThreadCost(1);
    testThreadCost(2);
    testThreadCost(4);
    testThreadCost(8);
    testThreadCost(16);
    return 0;
}