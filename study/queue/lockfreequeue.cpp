#include <bits/stdc++.h>
#include <stdatomic.h>
#include <atomic>
#include <thread>
using namespace std;

class LockFreeQueue {
public:
    LockFreeQueue(int sz_): sz(sz_), data(sz_) {}

    void push(int v) {
        auto cnt = cur.fetch_add(1);
        if (cnt >= sz) return;
        data[cnt] = v;
    }

    int pop() {
        auto cnt = cur.fetch_sub(1);
        if (cnt >= 0) return data[cnt];
        return -1;
    }

    void print() {
        for (auto & v:data)
            cout << v << " ";
        cout << endl;
    }

private:
    int sz;
    atomic_int cur = 0;
    vector<int> data;
};

int main()
{
    LockFreeQueue q(10);
    q.print();
    mutex m;
    auto func = [&](int id) {
        q.push(id);
    };
    auto func2 = [&]() {
        auto v = q.pop();
        unique_lock lock(m);
        cout << "*" << v << "*" << endl;
    };
    vector<thread> threads;
    for (int i = 0; i < 200; i++) {
        if (i < 100)
            threads.emplace_back(func, i);
        else
            threads.emplace_back(func2);
    }
    for (auto & t:threads) {
        t.join();
    }
    q.print();
    return 0;
}