#include <bits/stdc++.h>

using namespace std;
int sum[26];
int main()
{
    string s;
    cin>>s;
    if(s.length() == 26)
        cout<<"-1"<<endl;
    else{
        for(int i = 0; i < s.length(); i++)
            sum[s[i] - 'a']++;
        cout<<s;
        for(int i = 0; i < 26; i++){
            if(sum[i] == 0){
                char c = i+'a';
                cout<<c<<endl;
                break;
            }
        }
    }
    return 0;
}
