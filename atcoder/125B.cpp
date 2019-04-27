#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	int v[n], c[n], ans = 0;
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, ans + (v[i] - c[i]));
	}
	cout<<ans<<endl;
	return 0;
}
