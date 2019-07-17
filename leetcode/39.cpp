#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> c = {1,2,4,6,8};
    int target = 100;
    vector<vector<int>> ans;
    sort(c.begin(), c.end(), greater<int>());
    int l = 0, r = c.size()-1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(target>=c[mid]) r = mid-1;
        else l = mid+1;
        cout<<l<<" "<<r<<endl;
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}
