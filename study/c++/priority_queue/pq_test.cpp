#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Ele
{
    string name;
    bool download;
};

struct CustomGreater
{
    public:
        bool operator()(const Ele & el, const Ele & er)
        {
            return el.download;
        }
};

int main()
{
    std::vector<int> a = {1, 2, 3};
    std::ranges::sort(a);
    priority_queue<Ele, vector<Ele>, CustomGreater> pq;
    pq.emplace("v1", false);
    pq.emplace("v2", true);
    cout << pq.top().name << " " << pq.top().download << endl;
    return 0;
}