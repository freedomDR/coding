#include <bits/stdc++.h>

using namespace std;
int ans[100000];

int main()
{
    long long a, b;
    cin>>a>>b;
    long long tmp = (a+b)*2;
    tmp = sqrt(tmp);
    if(tmp * (tmp+1) <= (a+b)*2) {}
    else tmp--;
    int a_len = 0, a_sum = 0;
    for(int i = (tmp <= a ? tmp:a); a_sum < a && i > 0;){
        a_len++;
        ans[i] = 1;
        a_sum += i;
        i = (a-a_sum) <= (i-1) ? (a-a_sum) : (i-1);  
    }
    cout<<a_len<<endl;
    for(int i = 1; i <= tmp; i++) 
        if(ans[i] == 1) printf("%d ", i);
    cout<<endl<<tmp-a_len<<endl;
    for(int i = 1; i <= tmp; i++) 
        if(ans[i] == 0) printf("%d ", i);
    return 0;
}
