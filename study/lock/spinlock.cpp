#include <bits/stdc++.h>
#include <unistd.h>
#include <atomic>
#include <thread>
using namespace std;

class SpinLock {
public:
    void lock() {
        while(flag.test_and_set(memory_order::acquire)) {
            if (current_id == this_thread::get_id())
                break;
        }
        current_id = this_thread::get_id();
    }

    void unlock() {
        flag.clear(memory_order::release);
    }
private:
    atomic_flag flag = false;
    thread::id current_id;
};

int main()
{
    SpinLock lock;
    lock.lock();
    thread child([&]() {
        cout << "start" << endl;
        lock.lock();
        cout << "end" << endl;
    });
    lock.lock();
    sleep(5);
    lock.unlock();
    child.join();
    return 0;
}