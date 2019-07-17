#include <bits/stdc++.h>

using namespace std;

int shipWithinDays(vector<int>& weights, int D)
{
    int left = *max_element(weights.begin(), weights.end()), right = 25e6;
    while(left < right)
    {
        int mid = left+(right-left)/2, cur=0, need = 1;
        for(int i = 0; i < weights.size() && need <= D; cur += weights[i++])
        {
            if(cur+weights[i] > mid)
            {
                cur = 0;need++;
            }
        }
        if(need > D) left = mid+1;
        else right = mid;
    }
    return left;
}

int main()
{
    int N,D;cin>>N>>D;
    vector<int> weights(N);
    for(int i = 0; i < N; i++) cin>>weights[i];
    cout<<shipWithinDays(weights, D)<<endl;
    return 0;
}
