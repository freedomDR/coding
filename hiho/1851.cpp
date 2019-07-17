#include <bits/stdc++.h>

using namespace std;
int ans[100050], n[100050];
vector<vector<int>> nn(100050); 
int main()
{
    int N, D;
    cin>>N>>D;
    n[1] = 0;n[1] = 1; ans[1] = -1;
    for(int i = 2; i <= N; i++)
    {    
        cin>>n[i];
        nn[n[i]].push_back(i);
    }
    for(int i = 0; i <= N; i++){
        for(auto j: nn[i+D-1]){
            ans[j] = i;
            cout<<j<<endl;
        }
    }
    for(int i = 1; i <= N; i++)
        cout<<ans[i]<<endl;
    return 0;
}
