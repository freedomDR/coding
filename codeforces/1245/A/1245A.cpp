#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		if(a == 1 || b == 1) 
		{
			cout << "Finite" << endl;
		}else if(a == b) 
		{
			cout << "Infinite" << endl;
		}else if(__gcd(a,b) == 1)
		{
			cout << "Finite" << endl;
		}else
		{
			cout << "Infinite" << endl;
		}
	}
	return 0;
}
