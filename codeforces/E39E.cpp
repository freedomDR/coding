#include <bits/stdc++.h>

using namespace std;
char s[200050];
int sum[10];

int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(s, 0, sizeof(s));
        scanf("%s", s);
        int len = strlen(s);
        cout<<"len: "<<len<<endl;
        int mid = 0;
        for(int i = 0; i < len; i++){
            mid += (s[i]-'0');
        }
        if(mid == 1 && s[0] == '1'){
            for(int i = 0; i < len-2; i++)
                cout<<'9';
            cout<<endl;
        }else{
            for(int i = 0; i < 10; i++)
                sum[i] = 0;
            for(int i = 0; i < len; i++){
                sum[s[i] - '0']++;
            }
            int change_sum = 0;
            for(int i = 0; i < 10; i++){
                change_sum += sum[i]%2;
            }
            for(int i = len-1; 1;i--){
                int check = 1;
                sum[s[i]-'0']--;
                for(int j = 9; j > -1; j--){
                    if(sum[j]%2 == 1){
                        s[i] = '0'+j;
                        check = 0;
                        sum[j]++;
                        break;
                    }
                }
                if(check)
                    break;
            }
            printf("%s\n", s);
        }
    }
    return 0;
}
