#include <bits/stdc++.h>
#include <chrono>
#include <cstddef>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <ratio>
#include <streambuf>
#include <thread>
#include <type_traits>
#include <vector>

using namespace std;

// https://stackoverflow.com/questions/3017162/how-to-get-total-cpu-usage-in-linux-using-c
void collect_cpu()
{
    /// cpu  593720 0 602477 162876406 15088 0 35488 0 0 0
    /// cpu0 71930 0 75886 20333495 3980 0 19437 0 0 0
    auto t1 = std::chrono::high_resolution_clock::now();
    auto f = std::ifstream("/proc/stat");
    std::string name;
    long long user, nice, system, idle, iowait, irq, softirq;
    f >> name >> user >> nice >> system >> idle >> iowait >> irq >> softirq;
    auto total_1 = user+nice+system+idle+iowait+irq+softirq;
    auto work_1 = user+nice+system;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    auto f2 = std::ifstream("/proc/stat");
    f2 >> name >> user >> nice >> system >> idle >> iowait >> irq >> softirq;
    auto total_2 = user+nice+system+idle+iowait+irq+softirq;
    auto work_2 = user+nice+system;
    double cpu_usage = (work_2-work_1)*1.0/(total_2-total_1) * 100.0;
    std::cout << "worker: " << work_2 << std::endl;
    std::cout << "total: " << total_2 << std::endl;
    std::cout << "worker: " << work_1 << std::endl;
    std::cout << "total: " << total_1 << std::endl;
    std::cout << "worker " << work_2-work_1 << std::endl;
    std::cout << "total " << total_2-total_1 << std::endl;
    std::cout << "cpu_usage: " << cpu_usage << std::endl;
    
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> cost = t2-t1;

    std::cout << cost.count() << " milliseconds" << std::endl;
}

bool judgeEnv()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    auto f = std::ifstream("/proc/1/cgroup");
    string ss;
    string content;
    while (f >> ss)
        content += ss;
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> cost = t2-t1;
    std::cout << cost.count() << std::endl;
    return true;
}

void test()
{
    auto f = std::ifstream("/workspaces/coding/test.txt");
    std::string line;
    std::getline(f, line);
    std::getline(f, line);
    while(!f.eof())
    {
        std::string interface_name;
        f >> interface_name;
        if (interface_name.starts_with("lo"))
        {
            std::getline(f, line);
            std::cout << line << std::endl;
            continue;
        }
        long long val;
        f >> val >> val;
        f >> val;
        f >> val;
        f >> val >> val >> val >> val;
        f >> val >> val;
        f >> val;
        f >> val;
        f >> val >> val >> val >> val;
    }
}

int main()
{
    auto in_docker = judgeEnv();
    collect_cpu();
    test();


test
test
test
test
test
test

    return 0;
}