#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<string> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = 0;
        for(int i = 0; i < 5; i++)
        {
            vector<int> tmp;
            for(int j = 0; j < n; j++)
            {
                int val = 0;
                for(auto c:arr[j])
                {
                    if(c-'a'==i) val++;
                    else val--;
                }
                tmp.push_back(val);
            }
            sort(tmp.begin(), tmp.end());
            int tmp_ans = 0;
            for(int j = n-1, sums=0; j >= 0; j--)
            {
                sums += tmp[j];
                if(sums > 0) tmp_ans++;
                else break;
            }
            ans = max(ans, tmp_ans);
        }
        cout << ans << "\n";
    }
    return 0;
}