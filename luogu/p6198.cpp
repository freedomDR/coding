#include<bits/stdc++.h>

using namespace std;
int n;
int val = 1;
vector<int> arr(1e6+5), ans(1e6+5);
vector<vector<int>> pos(1e6+5, vector<int>());

void slove(int l, int r, int splitNum)
{
    /* cout << l << " " << r << endl; */
    if(l>r) return;
    vector<int> splitPos; //记录分割点
    // 二分查端点
    int st = lower_bound(pos[splitNum].begin(), pos[splitNum].end(), r) - pos[splitNum].begin();
    // splitNum 从r到l 按照val递增赋值
    for(int i = min(st, int(pos[splitNum].size()-1)); i >= 0 && pos[splitNum][i] >= l; i--)
    {
        if(pos[splitNum][i] <= r && arr[pos[splitNum][i]] == splitNum)
        {
            ans[pos[splitNum][i]] = val++;
            splitPos.push_back(pos[splitNum][i]);
        }
    }
    // l r 也可以作为分割点
    if(!splitPos.empty() && splitPos.back()!=l) splitPos.push_back(l-1);
    if(splitPos.front()!=r) splitPos.insert(splitPos.begin(),r+1);
    for(int i = splitPos.size()-2; i >= 0; i--)
    {
        slove(splitPos[i+1]+1, splitPos[i]-1, splitNum+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if(arr[i] == -1) arr[i] = arr[i-1]+1;
        pos[arr[i]].push_back(i);
    }
    slove(1, n, 1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
