#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;

int pow(int a, int i){
        int res = 1;
        while(i > 0){
                if(i & 1){
                        res = 1LL*res*a%mod;
                }
                a = 1LL*a*a%mod;
                i /= 2;
        }
        return res;
}

int inv(int t)
{
        return pow(t, mod-2);
}

int sum(vector<int> num)
{
        int fact = 1;
        int num_digits = 0;
        for(int i = 0; i < 10; i++)
                num_digits += num[i];
        for(int i = 1; i <= num_digits; i++)
                fact = 1LL* fact * i % mod;
        for(int i = 0; i < 10; i++){
                int tmp = 1;
                for(int j = 1; j <= num[i]; j++)
                        tmp = 1LL*tmp*j%mod;
                fact = 1LL*fact*inv(tmp)%mod;
        }
        int ten_num = 0;
        for(int i = 0, e = 1; i < num_digits; i++, e = 1LL*e*10%mod)
                ten_num = (ten_num + e)%mod;
        int sum = 0;
        for(int i = 0; i < 10; i++){
                if(num[i] == 0) continue;
                int tmp = fact;
                tmp = 1LL*tmp*num[i]%mod;
                tmp = 1LL*tmp*inv(num_digits)%mod;
                sum += 1LL*tmp*ten_num*i%mod;
        }
        return sum;
}

int main()
{
        int n;
        cin>>n;
        vector<int> num(10, 0);
        for(int i = 0; i < n; i++){
                int tmp;
                cin>>tmp;
                num[tmp]++;
        }
        int all = sum(num);
        if(num[0]){
                num[0]--;
                all -= sum(num);
                if(all < 0)
                        all += mod;
        }
        cout<<all<<endl;
        return 0;
}
