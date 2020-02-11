#include <bits/stdc++.h>
using namespace std;
const int N=101000;
int n,a[N],p[N],s[N];

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%d",a+i);
		p[i]=p[i-1]|a[i];
	}
	for(int i = n; i > 0; i--) {
		s[i]=s[i+1]|a[i];
	}
	int ans=-1,bs=0;
	for(int i = 1; i <= n; i++) {
		int x=a[i],y=p[i-1]|s[i+1];
		if ((x|y)-y>ans) {
			ans=(x|y)-y;
			bs=i;
		}
	}
	printf("%d",a[bs]);
	for(int i = 1; i <= n; i++) if (i!=bs) printf(" %d",a[i]);
	puts("");
}



