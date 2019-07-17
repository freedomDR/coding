#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, x, y;
    vector<pair<int, int>> n; 
    scanf("%d %d %d", &N, &x, &y);
    for(int i = 0; i < N; i++){
        int s, t;
        scanf("%d %d", &s, &t);
        n.push_back(make_pair(s, t));
    }
    sort(n.begin(), n.end(), [](pair<int, int> a, pair<int, int> b){ return a.first < b.first; });
    if(n[0].first > x){
        printf("-1\n");
        return 0;
    }
    int maxx1 = n[0].second;
    int maxx = n[0].second;
    int left = x;
    int ans = 1;
    for(int i = 0; i < N; i++){
        if(n[i].first <= left) {}
        else{
            if(maxx >= y){break;}
            left = maxx;
            ans++;
            if(maxx == maxx1) {ans = -1; break;}
            maxx1 = maxx;
        }
        maxx = max(maxx, n[i].second);
    }
    printf("%d\n", ans);
    return 0;
}
