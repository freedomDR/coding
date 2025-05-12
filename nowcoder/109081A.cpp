#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<char> title(n);
    for (int i = 0; i < n; i++) {
        cin >> title[i];
    }
    // for (int i = 0; i < n; i++) {
    //     cout << "*" << title[i] << "*";
    // }
    int max_v = -1, p = -1;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        auto pos = s.find("/");
        int score = atoi(s.substr(0, pos-0).c_str());
        // cout << "score: " << score << " max_v: " << max_v << " pos: " << pos << endl;
        if (score > max_v) {
            max_v = score;
            p = i;
        } else if (score==max_v&&title[p]>title[i]){
            p = i;
        }
    }
    cout << title[p] << endl;
    return 0;
}