#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p1, p2, p3;
    string s;
    cin>>p1>>p2>>p3>>s;
    int i = 0, flag = 0, len = 0;
    char pre, nxt;
    while(i < s.size()){
        if(flag == 0 && s[i] != '-') cout<<s[i++];
        else{
            if(flag == 0 && s[i] == '-') {pre = (i-1 >= 0 ? s[i-1]:0); flag = 1;len = 1;i++;}
            else if(flag == 1 && s[i] == '-')  {len++;i++;}
            else{
                char cur = s[i];
                /* cout<<"~~~"<<endl; */
                if((pre>='0'&&pre<='9'&&cur>='0'&&cur<='9') && len == 1){
                    if(pre >= cur){
                        while(len--) cout<<'-';
                    }
                    else if(pre == cur-1) ;
                    else if(p3 == 1){
                        char temp = pre+1;
                        while(temp<cur){
                            for(int j = 0; j < p2; j++) 
                                if(p1==3)cout<<'*';
                                else cout<<temp;
                            temp++;
                        }
                    }else{
                        char temp = cur-1;
                        while(temp>pre){
                            for(int j = 0; j < p2; j++)
                                if(p1 == 3)cout<<"*";
                                else cout<<temp;
                            temp--;
                        }
                    }
                }
                else if((pre>='a'&&pre<='z'&&cur>='a'&&cur<='z')&& len == 1){
                    /* cout<<pre<<" "<<cur<<endl; */
                    if(pre >= cur){
                        while(len--) cout<<'-';
                    }
                    else if(pre == cur-1) ;
                    else if(p3 == 1){
                        char temp = pre+1;
                        while(temp<cur){
                            for(int j = 0; j < p2; j++){ 
                                if(p1==3)cout<<'*';
                                else if(p1 == 2) cout<<(char)(temp-'a'+'A');
                                else cout<<temp;
                            }
                            temp++;
                        }
                    }else{
                        char temp = cur-1;
                        while(temp>pre){
                            for(int j = 0; j < p2; j++){
                                if(p1 == 3)cout<<"*";
                                else if(p1 == 2) cout<<(char)(temp-'a'+'A');
                                else cout<<temp;
                            }
                            temp--;
                        }
                    }
                }else{
                    while(len--) cout<<'-';
                }
            cout<<cur;
            i++;
            flag = 0;
            len = 0;
            pre = 0;
            cur = 0;
            }
        }
    }
    while(len--) cout<<'-';
    return 0;
}
