#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

vector<int> calc(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
{
    vector<int> e;
    e.push_back((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]));
    e.push_back((p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]));
    e.push_back((p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1]));
    sort(e.begin(), e.end());
    return e;
}

bool slove(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
{
    vector<int> e1, e2, e3, e4;
    e1 = calc(p1, p2, p3, p4);
    e2 = calc(p2, p1, p3, p4);
    e3 = calc(p3, p2, p1, p4);
    e4 = calc(p4, p2, p3, p1);
    if(!(e1[0] == e2[0] && e2[0] == e3[0] && e3[0] == e4[0]))
        return false;
    if(!(e1[1] == e2[1] && e2[1] == e3[1] && e3[1] == e4[1]))
        return false;
    if(!(e1[2] == e2[2] && e2[2] == e3[2] && e3[2] == e4[2]))
        return false;
    if(e1[0] != e1[1])
        return false;
    if(e1[1] == e1[2])
        return false;
    return true;
}

int main()
{
    vector<int> p1(2), p2(2), p3(2), p4(2);
    cin >> p1[0] >> p1[1];
    cin >> p2[0] >> p2[1];
    cin >> p3[0] >> p3[1];
    cin >> p4[0] >> p4[1];
    auto ans = slove(p1, p2, p3, p4);
    fmt::print("{}\n", ans);
    return 0;
}
