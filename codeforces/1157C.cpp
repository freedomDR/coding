#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	int a[n], l, r, v = 0;
	string ans;
	for(int i = 0; i < n; i++) cin>>a[i];
	l = 0; r = n-1;
	while(l <= r)
	{
		if(max(a[l], a[r]) <= v) break;
		if(a[l] == a[r])
		{
			int ll = l+1, rr = r-1, llen = 1, rlen = 1;
			while(ll < r){if(a[ll] <= a[ll-1]) break; ll++;llen++;}
			while(rr > l){if(a[rr] <= a[rr+1]) break; rr--;rlen++;}
			if(llen > rlen) {ans += "L"; v = a[l]; l++;}
			else {ans += "R"; v = a[r]; r--;}
			continue;
		}
		if(min(a[l], a[r]) > v )
		{
			if(a[l] < a[r]) {ans += "L";v = a[l];l++;}
			else {ans += "R";v = a[r];r--;}
		}
		else
		{
			if(a[l] < a[r]) {ans += "R";v = a[r]; r--;}
			else {ans += "L"; v = a[l];l++;}
		}
	}
	cout<<ans.size()<<endl;
	cout<<ans<<endl;
	return 0;
}
