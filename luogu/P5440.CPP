#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int t, miracle[66666], tot, a[1000], a_len;
int d[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isPrime(int val)
{
    for(int i = 2; i * i <= val; i++)
    {
        if(val%i == 0) return false;
    }
    return true;
}

int main()
{
    #ifdef LOCAL
        freopen("luogu/p5440.in", "r", stdin);
    #endif
    for(int i = 1; i <= 12; i++)
    {
        for(int j = 0; d[j] <= m[i]; j++)
        {
            int val = i*100+d[j];
            if(isPrime(val)) a[a_len++] = val;
        }
    }
    for(int i = 4; i <= 9999; i+=4)
        if((i%100||!(i%400)) && isPrime(i*10000+229))
            miracle[tot++] = i*10000+229;
    for(int i = 1; i <= 9999; i++)
        for(int j = 0; j < a_len; j++)
        {
            int val = i*10000+a[j];
            if(isPrime(val)) miracle[tot++] = val;
        }
    cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int cnt = 0;
        for(int i = 0; i < tot; i++)
        {
            int tmp = miracle[i], flag = 1;
            for(int j = 7; j>=0 && flag; j--, tmp/=10)
            {
                if(s[j]=='-' || tmp%10==(s[j]-'0')) continue;
                else flag = 0;
            }
            cnt += flag;
        }
        cout << cnt << endl;
    }
    return 0;
}