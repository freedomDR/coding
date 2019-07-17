#include <bits/stdc++.h>

using namespace std;
int n[200010];

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> ans;
    for(int i = 2; i <= N; i++){
        int tmp = 0;
        scanf("%d", &tmp);
        n[i] = tmp;
    }
    int f = N;
    ans.push_back(N);
    while(f != 1){
        ans.push_back(n[f]);
        f = n[f];
    }
    while(!ans.empty()){
        printf("%d ", ans.back());
        ans.pop_back();
    }
    printf("\n");
    return 0;
}
