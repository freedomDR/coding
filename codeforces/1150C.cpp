#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ones = 0, twos = 0, sums = 0;
	for(int i = 0; i < n; ++i)
	{
		int v; cin>>v;
		if(v == 1) ++ones;
		if(v == 2) ++twos;
		sums += v;
	}
	int prime[sums+1];
	for(int i = 0; i < sums+1; ++i) prime[i] = -1;
	prime[0] = 0; prime[1] = 0;
	for(int i = 2; i < sums+1; ++i)
	{
		if(prime[i] != -1) continue;
		prime[i] = 1;
		for(int j = i+i; j < sums+1; j += i)
		{
			prime[j] = 0;
		}
	}
	vector<int> ans;
	while(sums)
	{
		if(prime[sums-1] == 1) 
		{
			if(ones > 0)
			{
				--sums;--ones;
				ans.push_back(1);
			}else
			{
				sums -= 2;
				--twos;
				ans.push_back(2);
			}
		}
		else 
		{
			if(twos > 0)
			{
				sums -= 2;
				--twos;
				ans.push_back(2);
			}else
			{
				--sums;
				--ones;
				ans.push_back(1);
			}
		}
	}
	for(int i = n-1; i >= 0; --i) cout<<ans[i]<<" ";
	return 0;
}
