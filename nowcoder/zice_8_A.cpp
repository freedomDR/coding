#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int minn = 1e9, maxx = 0, ans = 0;
    int tmp = 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        tmp += arr[i];
        if(i >= k)
        {
            tmp -= arr[n-i];
        }
        if(i >= k-1)
        {
            minn = min(minn, tmp);
            maxx = max(maxx, tmp);
            ans = max(ans, maxx-minn);
        }
    }
    double ret = ans*1.0/k;
    cout << ret << endl;
    return 0;
}
