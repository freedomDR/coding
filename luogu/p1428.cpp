#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> fish(n);
    for(int i = 0; i < n; i++) cin >> fish[i];
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int tmp = 0;
        for(int j = 0; j < i; j++){
            if(fish[j] < fish[i]) tmp++;
        }
        ans[i] = tmp;
    }
    for(auto& it:ans)
        cout << it << " ";
    return 0;
}
