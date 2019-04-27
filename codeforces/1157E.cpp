#include<bits/stdc++.h>
const int N = 250000;
int a[N], b[N], c[N];
int n;
using namespace std;
int main()
{
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < n; i++)
	{
		int v; cin>>v;
		b[v]++;
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0)
		{
			int j = 0;
			while(b[j] == 0) j++;
			c[i] = j; b[j]--;
			continue;
		}
		int j = n - a[i];
		while(b[j%n] == 0) j++;
		c[i] = (j%n+a[i])%n; b[j%n]--;
	}
	for(int i = 0; i < n; i++)
		cout<<c[i]<<" ";
	return 0;
} 
