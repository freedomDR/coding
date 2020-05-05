#include<bits/stdc++.h>

using namespace std;


template<typename T> class Fenwick
{
    public:
        Fenwick(int sz):arr(sz+1), sz(sz){}
        ~Fenwick(){}
        inline int lowbit(int x) {return x&-x;}
        inline void add(int pos, T t)
        {
            for(int i = pos; i <= sz; i += lowbit(i))
                arr[i] += t;
        }
        int findk(int k)
        {
            int ans = 0, now = 0;
            for(int i = 20; i >= 0; i--)
            {
                ans += (1<<i);
                if(ans>sz||now+arr[ans]>=k) ans-=(1<<i);
                else now+=arr[ans];
            }
            return ans+1;
        }
    private:
        vector<T> arr;
        int sz;
};

int main()
{
    int n; cin >> n;
    vector<int> a(n+1), idx(n+1);
    for(int i = 1; i <= n; i++) {cin >> a[i];idx[i]=a[i];}
    sort(a.begin()+1, a.end());
    int sz = unique(a.begin()+1, a.end())-a.begin()-1;
    for(int i = 1; i <= n; i++) {idx[i] = lower_bound(a.begin()+1, a.begin()+sz+1, idx[i])-a.begin();}
    // for(int i = 1; i <= n; i++) cout << idx[i] << endl;
    Fenwick<int> f(sz);
    for(int i = 1; i <= n; i++)
    {
        f.add(idx[i], 1);
        if(i&1) {cout << a[f.findk((i+1)>>1)] << endl;}
    }
    return 0;
}