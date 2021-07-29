#include<iostream>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int ans = 0, sums = 0;
        for(int i = 1; i < 5000; i += 2)
        {
            ans++;
            sums += i;
            if(sums >= n)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}