#include <bits/stdc++.h>
#include <deque>
using namespace std;

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 15);
    //usage: x = dis(gen)
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = dis(gen);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    deque<int> min_d, max_d;
    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!min_d.empty()&&arr[i]<arr[min_d.back()]) min_d.pop_back();
        min_d.push_back(i);
        while (!max_d.empty()&&arr[i]>arr[max_d.back()]) max_d.pop_back();
        max_d.push_back(i);
        while (arr[max_d.front()]-arr[min_d.front()]>1) {
            if (l==max_d.front()) max_d.pop_front();
            if (l==min_d.front()) min_d.pop_front();
            l++;
        }
        ans = max(i-l+1, ans);
    }
    cout << ans << endl;
    return 0;
}