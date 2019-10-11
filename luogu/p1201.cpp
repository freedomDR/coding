#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> pos(N);
    unordered_map<string, int> money;
    for(int i = 0; i < N; i++)
    {
        cin >> pos[i];
    }
    for(int i = 0; i < N; i++)
    {
        string s; cin >> s;
        int puts, num;
        cin >> puts >> num;
        money[s] -= puts;
        if(num == 0) continue;
        money[s] += puts%num;
        for(int j = 0; j < num; j++)
        {
            string to; cin >> to;
            money[to] += puts/num;
        }
    }
    for(int i = 0; i < N; i++)
    {
        cout << pos[i] << " " << money[pos[i]] << endl;
    }
    return 0;
}
