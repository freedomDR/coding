#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m_res = 0, res = 0, month = -1;
    for(int i = 0; i < 12; i++){
        int val;cin>>val;
        if(month == -1){
            if(res+300 < val) {month = i+1; continue;}
            res = res+300 - val;
            m_res += (res/100) * 100;
            res %= 100;
        }
    }
    if(month == -1) cout<<(m_res + m_res/5.0)*1.0+res<<endl;
    else cout<<"-"<<month<<endl;
    return 0;
}
