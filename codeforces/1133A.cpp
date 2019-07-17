#include <bits/stdc++.h>

using namespace std;

int main()
{
    string start, end;
    cin>>start>>end;
    int startint = stoi(start.substr(0, 2))*60 + stoi(start.substr(3,5));
    int endint = stoi(end.substr(0, 2))*60+ stoi(end.substr(3,5));
    int fi = (startint+endint)/120, se = (startint+endint)/2 % 60;
    cout.fill('0');cout.width(2);
    cout<<fi<<":";
    cout.fill('0');cout.width(2);
    cout<<se<<endl;
    return 0;
}
