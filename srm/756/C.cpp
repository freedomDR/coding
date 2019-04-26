#include <bits/stdc++.h>

using namespace std;

class NewBanknote
{
public:
    vector<int> coins;

    int get(int t)
    {
        int res = 0;
        for(int i = coins.size()-1; i >= 0 && t > 0; i--)
        {
            res += t/coins[i];
            t %= coins[i];
        }
        return res;
    }

    vector<int> fewestPieces(int nb, vector<int> pack)
    {
        int a = 1, b = 2, c = 5;
        for(int i = 0; i < 5; i++)
        {
            coins.push_back(a);
            coins.push_back(b);
            coins.push_back(c);
            a*=10;
            b*=10;
            c*=10;
        }
        vector<int> ans;
        for(int i = 0; i < pack.size(); i++)
        {
            int v = get(pack[i]);
            for(int j = 1; 1ll*j*nb <= 1ll*pack[i]; j++)
            {
                v = min(v, j + get(pack[i]-j*nb));
            }
            ans.push_back(v);
        }
        return ans;
    }

};

int main()
{
    NewBanknote* app = new NewBanknote();
    int nb, n;cin>>nb>>n;
    vector<int> pack(n);
    for(int i = 0; i < n; i++) cin>>pack[i];
    vector<int> ans = app->fewestPieces(nb, pack);
    for(int v:ans) cout<<v<<" ";
    delete app;
    return 0;
}
