#include <bits/stdc++.h>

using namespace std;

int main()
{
        string s;
        cin>>s;
        string::size_type tmp1 = s.find("ABC");
        string::size_type tmp2 = s.find("ACB");
        string::size_type tmp3 = s.find("BAC");
        string::size_type tmp4 = s.find("CAB");
        string::size_type tmp5 = s.find("CBA");
        string::size_type tmp6 = s.find("BCA");
        if(tmp1 != string::npos || tmp2 != string::npos
                ||tmp3 != string::npos || tmp4 != string::npos
                ||tmp6 != string::npos || tmp5 != string::npos)
                cout<<"Yes"<<endl;
        else
                cout<<"No"<<endl;
        return 0;
}
