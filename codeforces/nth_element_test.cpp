#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a{4,2,5,3,1,9,7,6,8,0};
    nth_element(a.begin(),a.begin()+a.size()/2, a.end());
    for_each(a.begin(), a.end(), [](const int& n){cout<<n<<endl;});
    return 0;
}
