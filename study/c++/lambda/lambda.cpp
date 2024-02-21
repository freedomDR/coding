#include <bits/stdc++.h>
#include <unistd.h>

#include <exception>
#include <functional>
#include <thread>

using namespace std;

void ff(std::function<void()> job) { job(); }

int main() {
    std::cout << "1111" << std::endl;
    auto promise = std::make_shared<std::promise<void>>();
    std::string s = "hello";
    auto f = [&, s]() -> void {
        try {
            sleep(10);
            std::cout << s << std::endl;
            std::cout << "f: " << std::this_thread::get_id() << std::endl;
            promise->set_value();
            // throw exception();
        } catch (...) {
            promise->set_exception(std::current_exception());
        }
    };
    std::thread t(ff, f);
    t.join();
    promise->get_future().get();

    std::cout << "cur: " << std::this_thread::get_id() << std::endl;
    std::cout << "ok" << endl;

    return 0;
}