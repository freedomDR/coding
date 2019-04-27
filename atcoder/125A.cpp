#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,t;cin>>a>>b>>t;
	int ans = max(0, (t/a)*b);
	cout<<ans<<endl;
	return 0;
}
