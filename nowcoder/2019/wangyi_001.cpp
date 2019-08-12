#include<bits/stdc++.h>
using namespace std;
typedef struct {
    int d;
    int p;
}Work;
typedef struct {
    int a;
    int pos;
}Buddy;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<Work> works(N);
    vector<Buddy> buddys(M);
    vector<int> ans(M);
    for(int i = 0; i < N; i++) {
        cin >> works[i].d >> works[i].p;
    }
    for(int i = 0; i < M; i++) {
        cin >> buddys[i].a;
        buddys[i].pos = i;
    }
    sort(works.begin(), works.end(), [](Work w1, Work w2) {return w1.d < w2.d;});
    sort(buddys.begin(), buddys.end(), [](Buddy w1, Buddy w2) {return w1.a < w2.a;});
    for(int i = 0, temp = 0; i < N; i++) {
        temp = max(temp, works[i].p);
        works[i].p = temp;
    }
    int left = 0, pos = 0;
    while(left < N && pos < M) {
        if(buddys[pos].a >= works[left].d) left++;
        else {
            ans[buddys[pos].pos] = left==0?0:works[left-1].p;
            pos++;
        }
    }
    for(int i = pos; i < M; i++) {
        ans[buddys[i].pos] = works.back().p;
    }
    for(int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
