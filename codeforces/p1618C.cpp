#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    while(a%b)
    {
        long long c = b;
        b = a%b;
        a = c;
    }
    return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<long long> odd, even;
        for(int i = 1; i <= n; i++)
        {
            long long tmp; cin >> tmp;
            if(i%2==0) even.push_back(tmp);
            else odd.push_back(tmp);
        }
        long long v1 = odd[0], v2 = even[0];
        for(auto &v:odd) v1 = gcd(v, v1);
        for(auto &v:even) v2 = gcd(v, v2);
        if(v1+v2 == 2 || v1 == v2)
            cout << 0 << endl;
        else
        {
            long long ans = 0;
            bool flag = true;
            for(auto &v:odd) 
            {
                if(v%v2 == 0)
                    flag = false;
            }
            if(flag) {cout << v2 << endl; continue;}
            flag = true;
            for(auto &v:even) 
            {
                if(v%v1 == 0)
                    flag = false;
            }
            if(flag) {cout << v1 << endl; continue;}
            cout << 0 << endl;
        }


    }
    return 0;
}
