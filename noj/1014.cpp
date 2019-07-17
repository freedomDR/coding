#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        stack<int> judge;
        int i = 0;
        for(; i < s.length(); i++){
            if(s[i] =='(' || s[i] == '[' || s[i] == '{')
                judge.push(s[i]);
            else{
                if(judge.empty()) break;
                char t = judge.top();
                if(s[i] == ')' && t == '('){}
                else if(s[i] == '}' && t == '{'){}
                else if(s[i] == ']' && t == '['){}
                else break;
                judge.pop();
            }
        }
        if(judge.empty() && i == s.length()) cout<<"Valid"<<endl;
        else cout<<"Invalid"<<endl;
    }
    return 0;
}
