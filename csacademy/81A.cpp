#include <bits/stdc++.h>

using namespace std;

int main()
{
        int Q, X;
        cin>>Q>>X;
        vector<pair<int, int>> w(Q);
        for(int i = 0; i < Q; i++){
                int tmp1, tmp2;
                cin>>tmp1>>tmp2;
                w[i] = make_pair(tmp1, tmp2 - tmp1);
        }
        sort(w.begin(), w.end(), [](pair<int, int> a, pair<int, int> b){return a.second > b. second;});
        int ans = X;
        for(int i = 0; i < 12; i++){
                for(int j = 0; j < Q; j++){
                        if(w[j].first <= ans && w[j].second >= 0){
                                ans += w[j].second;
                                break;
                        }
                }       
                /* cout<<ans<<endl; */
        }
        cout<<ans<<endl;
        return 0;
}
