#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n, p;
        string s;
        cin>>n>>p>>s;
        int ans = 0;
        for(int i = 0; i < n-p; i++){
                if(s[i] == '.' || s[i+p] == '.'){
                        if(s[i] == s[i+p]){s[i] = '1'; s[i+p] = '0';}
                        else if(s[i] == '.'){
                                if(s[i+p] == '1') s[i] = '0';
                                else s[i] = '1';
                        }else{
                                if(s[i] == '1') s[i+p] = '0';
                                else s[i+p] = '1';
                        }
                        ans = 1;
                        break;
                }
                if(s[i] != s[i+p]){
                        ans = 1;
                        break;
                }
        }
        if(ans){
                for(int i = 0; i < n; i++){
                        if(s[i] == '.') cout<<"0";
                        else cout<<s[i];
                }
                cout<<endl;
        }else{
                cout<<"No"<<endl;
        }
        return 0;
}
