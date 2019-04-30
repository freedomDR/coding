#include <bits/stdc++.h>

using namespace std;

class MtGFight{

public:
    vector<int> findGoodFight(vector<int> p, vector<int> t){
        for(int i = 0; i < p.size(); ++i) {
            for(int j = i+1; j < p.size(); ++j){
                if(p[j] < t[i] && p[i] >= t[j]) return vector<int>{i, j};
                if(p[i] < t[j] && p[j] >= t[i]) return vector<int>{j, i};
            }
        }
        return vector<int>();
    }
};

int main(){
    MtGFight* app = new MtGFight();
    int n; cin>>n;
    vector<int> p(n), t(n);
    for(int i = 0; i < n; ++i) cin>>p[i];
    for(int i = 0; i < n; ++i) cin>>t[i];
    vector<int> ans = app->findGoodFight(p, t);
    for(int v:ans) cout<<v<<" ";
    return 0;
}
