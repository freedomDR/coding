#include<bits/stdc++.h>

using namespace std;

struct d
{
    int a;
    int b;
    int c;
    int pos;
    int a_min;
    int a_max;
    int point;
    bool operator <(const d & val) const
    {
        if(a+b-c != val.a+val.b-val.c)
        {
            return a+b-c < val.a+val.b-val.c;
        }
        return a_max < val.a_max || (a_max == val.a_max && a_min < val.a_min);
    }
};

int main()
{
    #ifdef LOCAL
        freopen("./codeforces/p1607H.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int t;
        cin >> t;
        vector<d> arr(t);
        for(auto & v : arr)
            cin >> v.a >> v.b >> v.c;
        for(int i = 0;  i< arr.size(); i++)
        {
            arr[i].pos = i;
            arr[i].a_min = max(0, arr[i].a-arr[i].c);
            arr[i].a_max = arr[i].a + min(0, arr[i].b-arr[i].c);
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0, min_a_max = 0; i < arr.size(); i++)
        {
            if(i == 0 || arr[i].a+arr[i].b-arr[i].c != arr[i-1].a+arr[i-1].b-arr[i-1].c || min_a_max < arr[i].a_min )
            {
                ans++;
                min_a_max = arr[i].a_max;
                arr[i].point = min_a_max;
            }
            else
            {
                arr[i].point = min_a_max;
            }
        }
        sort(arr.begin(), arr.end(), [](d & v1, d & v2){ return v1.pos < v2.pos;});
        cout << ans << endl;
        for(auto & v : arr)
        {
            int v1 = abs(v.a-v.point);
            int v2 = v.c-abs(v.a-v.point);
            cout << v1 << " " << v2 << endl;
            assert(v1 >= 0);
            assert(v2 >= 0);
        }
    }
    return 0;
}