#include<cstdio> 
#include<cstring>
#include<iostream> 
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,s,t,now=0;
    cin>>m>>s>>t;
    int s1=0,s2=0;//存放跑步能走的距离和用闪烁能走的距离
    for(int i=1;i<=t;i++)//一个个时间去推
    {
        s1+=17;//闪现和跑步分批进行
        if(m>=10) {s2+=60;m-=10;}//能够闪现这肯定要闪现的，
        else m+=4;//没蓝这一回合就用来回蓝
        if(s2>s1) s1=s2;//闪现的快了就把跑步的替换成闪现的
        if(s1>s){//跑出去了就输出当前时间
            cout<<"Yes"<<endl<<i<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl<<s1<<endl;//时间都用完了还没跑出去，输出“No”和s1的值，（由于闪现可走距离一旦大于跑步的跑步的距离就会被替换，这时跑的距离远的一定是s1）:Q
}
