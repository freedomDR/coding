#include <bits/stdc++.h>
#include <unistd.h>

#include <exception>
#include <functional>
#include <future>
#include <memory>
#include <thread>
#include <vector>

using namespace std;

void ff(std::function<void()> job) { job(); }


void test1() 
{
    std::vector<std::shared_ptr<std::promise<void>>> promises;
    promises.reserve(10);
    std::vector<std::thread> ts;
    for (int i = 0; i < 10; i++)
    {
        auto promise = std::make_shared<std::promise<void>>();
        promises.emplace_back(promise);
        auto s = "hello";
        auto f = [&, promise, s]() -> void {
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
        ts.push_back(std::thread(ff, f));
    }
    for(auto & t:ts)
        t.join();
    for(auto & promise:promises)
        promise->get_future().get();

    std::cout << "cur: " << std::this_thread::get_id() << std::endl;
}

void test2()
{
#ifdef __cpp_explicit_this_parameter
    auto func = [](this auto self, int remain = 10) -> void
    {
        if (remain == 0)
            return;
        self(remain-1);
    };
    func(100);
#else
    auto func = [](auto self, int remain) -> void {
        if (remain == 0)
            return;
        self(self, remain-1);
    };
    func(func, 100); 
#endif
}

int main() 
{
    // test1();
    test2();
    return 0;
}