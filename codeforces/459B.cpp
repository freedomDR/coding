#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, string> M;
    int n, m;
    string name, ip, cmd;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>name>>ip;
        M[ip] = name;
    }
    for(int i = 0; i < m; i++){
        cin>>name>>ip;
        ip.pop_back();
        cout<<name<<" "<<ip<<"; #"<<M[ip]<<endl;
    }
    return 0;
}
