#include <bits/stdc++.h>

using namespace std;

struct p{
    int x, y;
};
int dist(p p1, p p2){
    return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}
long long ans_0, ans_1;
int main()
{
    map<int, vector<p>> points;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int tx, ty;
        scanf("%d %d", &tx, &ty);
        points[max(tx, ty)].push_back({tx, ty});
    }
    for(auto i : points) {
        sort(points[i.first].begin(), points[i.first].end(), [](p p1, p p2){return p1.x < p2.x || p1.y > p2.y;});
    }
    points[0].push_back({0, 0});
    auto pre = points.begin();
    for(auto i : points){
        if(i.first == pre->first){continue;}
        long long tmp = dist(i.second.front(), i.second.back());
        long long tmp_0 = min(ans_0 + dist(pre->second.front(), i.second.back()), ans_1 + dist(pre->second.back(), i.second.back()))+tmp; 
        long long tmp_1 = min(ans_0+ dist(pre->second.front(), i.second.front()), ans_1+ dist(pre->second.back(), i.second.front()))+tmp; 
        pre++;
        ans_0 = tmp_0; ans_1 = tmp_1;
    }
    cout<<min(ans_0, ans_1)<<endl;
    return 0;
}
