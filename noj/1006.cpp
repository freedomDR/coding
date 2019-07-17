#include <bits/stdc++.h>

using namespace std;

vector<int> getnums(string s){
    vector<int> res;
    while(1){
        int pos = s.find('.');
        string mid;
        if(pos == std::string::npos) mid = s;
        else mid = s.substr(0, pos);
        res.push_back(atoi(mid.c_str()));
        if(pos == std::string::npos) break;
        s = s.substr(pos+1);
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    string a,b;
    while(n--){
        cin>>a>>b;
        vector<int> aa = getnums(a);
        vector<int> bb = getnums(b);
        int mlength = max(aa.size(), bb.size());
        aa.resize(mlength);
        bb.resize(mlength);
        auto ait = aa.cbegin();
        auto bit = bb.cbegin();
        int ans = 0;
        for(; ait != aa.cend() && bit != bb.cend(); ait++, bit++){
            if(*ait > *bit){
                ans = 1;
                break;
            }else if(*ait < *bit){
                ans = -1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
