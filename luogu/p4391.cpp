#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 1e6+5;
char s[maxn];
int n, p[maxn];

int main()
{
    freopen("/Users/dongrui05/Downloads/P4391_3.in", "r", stdin);
    cin >> n;
    scanf("%s", s+1);
    if(n == 1)
    {
        cout << n << endl;
        return 0;
    }
    for(int i = 2; i <= n; i++)
    {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j+1]) j = p[j];
        if(s[j+1] == s[i]) j++;
        p[i] = j; 
    }
    cout << n-p[n] << endl;
    return 0;
}