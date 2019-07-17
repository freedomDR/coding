#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, ss;
    bool find = false;
    while(cin>>s){
        if(!find && s.find('E') == string::npos) ss += s;
        else {
            if(!find) { ss += s.substr(0, s.find('E'));find = true;break;}
        }
    }
    vector<pair<int, int>> ans11, ans21;
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    for(char c:ss){
        if(c == 'W') {a1++;a2++;}
        if(c == 'L') {b1++;b2++;}
        if(max(a1, b1) >= 11 && abs(a1-b1) >= 2) {ans11.push_back(make_pair(a1, b1)); a1 = b1 = 0;}
        if(max(a2, b2) >= 21 && abs(a2-b2) >= 2) {ans21.push_back(make_pair(a2, b2)); a2=b2=0;}
    }
    ans11.push_back(make_pair(a1, b1));
    ans21.push_back(make_pair(a2, b2));
    for(auto item:ans11) cout<<item.first<<":"<<item.second<<endl;
    cout<<endl;
    for(auto item:ans21) cout<<item.first<<":"<<item.second<<endl;
    return 0;
}
