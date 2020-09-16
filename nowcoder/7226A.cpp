#include<iostream>
#include<set>

using namespace std;

int main()
{
    int n; cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        int v; cin >> v;
        s.insert(v);
    }
    auto t = s.begin();
    int n1 = *t, n2 = *(++t);
    t = s.end();
    int x1 = *(--t), x2 = *(--t);
    cout << x1-x2 << " ";
    cout << x1-n2 << " ";
    cout << x2-n2 << " ";
    cout << x2-n1 << "\n";

}