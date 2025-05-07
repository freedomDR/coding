#include <bits/stdc++.h>
#include <unistd.h>
#include <condition_variable>
#include <mutex>
#include <thread>
using namespace std;

class BlockingQueue {

public:
    BlockingQueue(int sz_): sz(sz_) {

    }

    void push(int v) {
        unique_lock<mutex> lock(in);
        if (sz == arr.size()) {
            not_full.wait(lock, [&](){return arr.size() < sz;});
        }
        arr.push(v);
        not_empty.notify_one();
    }

    int get() {
        unique_lock<mutex> lock(in);
        if (arr.size() == 0) {
            not_empty.wait(lock, [&](){return arr.size() > 0;});
        }
        auto v = arr.front();
        arr.pop();
        not_full.notify_one();
        return v;
    }

    
private:
    int sz;
    mutex in, out;
    condition_variable not_full, not_empty;
    queue<int> arr;
};

int main()
{
    BlockingQueue bq(10);
    for (int i = 0; i < 10; i++) {
        bq.push(i);
    }
    thread child([&]() {
        cout << "start" << endl;
        bq.push(11);
        cout << "end" << endl;
    });
    sleep(10);
    bq.get();
    child.join();
    return 0;
}