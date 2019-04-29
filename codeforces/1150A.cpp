#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, r;cin>>n>>m>>r;
	int s = INT_MAX, b = INT_MIN;
	for(int i = 0; i < n; ++i)
	{
		int v; cin>>v;
		s = min(s, v);
	}
	for(int i = 0; i < m; ++i)
	{
		int v; cin>>v;
		b = max(b, v);
	}
	if(b > s) cout<<(r%s + r/s*b)<<endl;
	else cout<<r<<endl;
	return 0;
}
