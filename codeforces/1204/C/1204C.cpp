#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n, 110));
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < (int)s.size(); j++) {
            if(s[j] == '1') dist[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    cin >> m;
    vector<int> p(m);
    for(int i = 0; i < m; i++) cin >> p[i];
    vector<int> ans;
    int first = p.front(), last = p.back();
    ans.push_back(first);
    for(auto it = p.begin()+2, pos = p.begin(); it < p.end(); it++) {
        if(dist[ans.back()-1][*it-1] < it-pos) {ans.push_back(*(it-1));pos = it-1;}
    }
    ans.push_back(last);
    cout << (int)ans.size() << endl;
    for(auto it:ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
