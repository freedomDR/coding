#include <bits/stdc++.h>

using namespace std;

auto reconstructQueue(vector<pair<int, int>>& people)
{
    vector<pair<int, int>> res;
    auto cmp = [](auto p1, auto p2){return p1.first>p2.first||(p1.first==p2.first&&p1.second<p2.second);};
    sort(people.begin(), people.end(), cmp);
    for(auto p:people)
    {
        res.insert(res.begin()+p.second, p);
    }
    return res;
}

int main()
{
    vector<pair<int, int>> people;
    people.push_back(make_pair(7, 0));
    people.push_back(make_pair(4, 4));
    people.push_back(make_pair(7, 1));
    people.push_back(make_pair(5, 0));
    people.push_back(make_pair(6, 1));
    people.push_back(make_pair(5, 2));
    auto ans = reconstructQueue(people);
    for(auto p:ans)
    {
        cout<<"["<<p.first<<", "<<p.second<<"], ";
    }
    return 0;
}
