#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;
    auto toBin = [](long long xx)
    {
        string ret = "";
        while(xx != 0)
        {
            const char c = xx%2+'0';
            ret.push_back(c); 
            xx /= 2;
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    };
    queue<string> q;
    set<string> s;
    s.insert(toBin(x));
    q.push(toBin(x)); 
    while(!q.empty())
    {
        string k = q.front();
        q.pop();
        if(k.size() > 100) continue;
        string k1 = k+"0";
        while(k1.back() == '0') k1.pop_back();
        reverse(k1.begin(), k1.end());
        if(!s.count(k1))
        {
            s.insert(k1);
            q.push(k1);
        }
        string k2 = k+"1";
        reverse(k2.begin(), k2.end());
        if(!s.count(k2))
        {
            s.insert(k2);
            q.push(k2);
        }
    }
    if(s.count(toBin(y)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
