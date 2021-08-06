#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, t;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<string> arr(2*n-1);
        vector<bool> f(2*n-1, true);
        for(int i = 0; i < 2*n-1; i++)
            cin >> arr[i];
        vector<int> cnt(26);
        for(int i = 0; i < m; i++)
        {
            fill(cnt.begin(), cnt.end(), 0);
            for(int j = 0; j < 2*n-1; j++)
                if(f[j] == true)
                    cnt[arr[j][i]-'a']++;
            int pos = 0;
            for(int j = 0; j < 26; j++)
                if(cnt[j]%2==1) pos = j;
            for(int j = 0; j < 2*n-1; j++)
                if(f[j] == true && (arr[j][i]-'a')!=pos)
                    f[j] = false;
            if(cnt[pos] == 1)
                break;
        }
        int tt = -1, tts = 0;
        for(int i = 0; i < n; i++) 
            if(f[i] == true)
            {
                tt = i;
                tts++;
            }
        assert(tt<=n-1);
        assert(tts==1);
        cout << arr[tt] << endl;
    }
}