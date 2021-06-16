#include<iostream>
#include<cstdio>

using namespace std;

void fib(int x)
{
	long long a1 = 1, a2 = 1;
	for(int i = 1; i <= x; i++)
	{
		if(i > 2)
		{
			a2 = a1+a2;
			a1 = a2-a1;
		}
		cout << "fib " << i <<  " = " << a2 << endl;
	}
}

const int N = 1010;
long long a[N], prefix[N], n, ans, c;

void dfs(int l, long long sums)
{
	if(sums > c)
	{
		return;
	}
	if(sums+prefix[l] <= c)
	{
		sums += prefix[l];
		ans = max(ans, sums);
		return;
	}
	ans = max(ans, sums);
	for(int i = l; i > 0; i--)
	{
		dfs(i-1, sums+a[i]);
	}
}

int main()
{
	// fib(45);
	#ifdef LOCAL
		freopen("./luogu/P5194_4.in", "r", stdin);
	#endif
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		prefix[i] = prefix[i-1]+a[i];
	}
	dfs(n, 0);
	cout << ans << endl;
	return 0;
}