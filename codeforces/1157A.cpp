#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	set<int> s;
	while(true)
	{
		if(s.count(n)) break;
		s.insert(n);
		n++;
		while(n%10 == 0) n /= 10;
	}
	cout<<s.size()<<endl;
	return 0;
}
