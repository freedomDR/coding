// #include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <iostream>
// #include <ratio>
#include <ratio>
#include <string>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

const string file_name = "/workspaces/coding/test.txt";

void test_cpp_iftream()
{
    auto time_1 = std::chrono::high_resolution_clock::now();
    auto f = std::ifstream(file_name);
    string read_line;
    while(!f.eof())
    {
        std::getline(f, read_line);
    }
    auto time_2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> cost = time_2-time_1;
    std::cout << "cost: " << cost.count() << "ms\n";
};

void test_linux_read()
{
    auto time_1 = std::chrono::high_resolution_clock::now();
    auto fd = open(file_name.c_str(), O_RDONLY);
    char buf[100];
    while(true)
    {
        int sz = read(fd, buf, 100);
        if(sz == 0)
            break;
    }
    close(fd);
    auto time_2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> cost = time_2-time_1;
    std::cout << "cost: " << cost.count() << "ms\n";
}

int main()
{
    test_cpp_iftream();
    test_linux_read();
    return 0;
}