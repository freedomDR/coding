#include <bits/stdc++.h>

using namespace std;

/*
 * 注意右移对于正数来说时除法求商, 对于负数来说情况不一样, -3>>1 的结果是-2;
 * 负进制表示要求余数必须为正
 */
string baseNeg2(int N)
{
    string res = "";
    while(N)
    {
        res = to_string(N&1) + res;
        N = -(N>>1);
    }
    return res;
}

int main()
{
    int val;
    cin>>val;
    cout<<baseNeg2(val)<<endl;
    return 0;
}
