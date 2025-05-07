#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Ele {
    string name;
    bool download;
};

struct CustomGreater {
    public:
        bool operator()(const Ele & el, const Ele & er) {
            return el.download;
        }
};

void customSortTest() {
    std::cout << "custom comp test" << endl;
    std::vector<int> a = {1, 2, 3};
    std::ranges::sort(a);
    priority_queue<Ele, vector<Ele>, CustomGreater> pq;
    pq.emplace("v1", false);
    pq.emplace("v2", true);
    cout << pq.top().name << " " << pq.top().download << endl;
}

void defaultTest() 
{
    std::priority_queue<int, vector<int>, less<int>> max_pq;
    std::priority_queue<int, vector<int>, greater<int>> min_pq;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    //usage: x = dis(gen)
    for (int i = 0; i < 10; i++) {
        max_pq.emplace(dis(gen));
        min_pq.emplace(dis(gen));
    }
    cout << "max_pq: ";
    while (!max_pq.empty()) {
        cout << max_pq.top() << " ";
        max_pq.pop();
    }
    cout << endl;
    cout << "min_pq: ";
    while (!min_pq.empty()) {
        cout << min_pq.top() << " ";
        min_pq.pop();
    }
    cout << endl;
}

void findMediumVal() {
    std::priority_queue<int, vector<int>, less<int>> max_pq;
    std::priority_queue<int, vector<int>, greater<int>> min_pq;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    //usage: x = dis(gen)
    vector<int> arr;
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        int x = dis(gen);
        arr.push_back(x);
        cnt++;
        if (max_pq.size() <= min_pq.size()) {
            max_pq.push(x);
        } else {
            min_pq.push(x);
        }
        // rebalance
        if (cnt>1&&max_pq.top()>min_pq.top()) {
            int max_pq_top = max_pq.top();
            int min_pq_top = min_pq.top();
            max_pq.pop(); min_pq.pop();
            max_pq.push(min_pq_top);
            min_pq.push(max_pq_top);
        }
        cout << "push: " << x << endl;
        cout << "sort arr: ";
        sort(arr.begin(), arr.end());
        for (auto & v:arr)
            cout << v << " ";
        cout << endl;
        cout << "media: " << max_pq.top() << endl;
    }
}

int main() {
    customSortTest();
    defaultTest();
    findMediumVal();
    return 0;
}