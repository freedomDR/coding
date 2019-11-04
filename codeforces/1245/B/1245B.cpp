#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, a, b, c;
	cin >> t;
	while(t--)
	{
		cin >> n >> a >> b >> c;
		int aa = 0, bb = 0, cc = 0;
		string s; cin >> s;
		for(auto it:s)
		{
			if(it == 'R') aa++;
			if(it == 'P') bb++;
			if(it == 'S') cc++;
		}
		int sums = 0;
		sums += (b > aa?aa:b) + (a>cc?cc:a) + (c>bb?bb:c);
		if(sums < (n-1)/2+1) {cout << "NO" << endl;}
		else
		{
			cout << "YES" << endl;
			string ans = "";
			for(auto it:s)
			{
				if(it == 'R') 
				{
					if(b > 0) ans += "P", b--;
					else if(c > bb && c != 0) ans += "S", c--;
					else ans += "R", a--;
					aa--;
				}else if(it == 'P')
				{
					if(c > 0) ans += "S", c--;
					else if(a > cc && a != 0) ans += "R", a--;
					else ans += "P", b--;
					bb--;
				}else
				{
					if(a > 0) ans += "R", a--;
					else if(c > bb && c != 0) ans += "S", c--;
					else ans += "P", b--;
					cc--;
				}
			}
			cout << ans << endl;
		} 
	}
	return 0;
}
