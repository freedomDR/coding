#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> odd, even;
        for (size_t i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x & 1)
                odd.push_back(x);
            else
                even.push_back(x);
        }
        if (is_sorted(begin(odd), end(odd)) && is_sorted(begin(even), end(even)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}