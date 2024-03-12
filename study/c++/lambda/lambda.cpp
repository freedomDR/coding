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

int main() {
    std::vector<std::shared_ptr<std::promise<void>>> promises;
    promises.reserve(10);
    //std::vector<std::promise<void>> promises3(10, std::promise<void>());
    //std::vector<std::unique_ptr<std::promise<void>>> promises4(10, std::make_unique<std::promise<void>>());
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
    std::cout << "ok" << endl;

    return 0;
}