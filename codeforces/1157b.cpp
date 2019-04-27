#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, f[10];
	string s;
	cin>>n;cin>>s;
	for(int i = 1; i < 10; i++) cin>>f[i];
	for(int i = 0; i < n; i++)
	{
		int v = s[i]-'0';
		if(f[v] > v)
		{
			s[i] = f[v]+'0';
			for(i++; i < n; i++)
			{
				int vv = s[i]-'0';
				if(f[vv] < vv) break;
				s[i] = f[vv]+'0';
			}
			break;
		}
	}
	cout<<s<<endl;
	return 0;
}
