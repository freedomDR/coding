#include <bits/stdc++.h>

using namespace std;

int main()
{
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        int r = 4, l = 50;
        if(a > 50) r++;
        if(b > 50) r++;
        if(c > 50) r++;
        if(d > 50) d++;
        cout<<r<<" "<<l<<endl;
        int tmp = 1;
        if(a > 50) tmp = 2;
        for(int i = 0; i < tmp; i++){
                for(int j = 0; j < 50; j++)
                        cout<<'A';
                cout<<endl;
        }
        tmp = 1;
        if(b > 50) tmp = 2;
        for(int i = 0; i < tmp; i++){
                for(int j = 0; j < 50; j++)
                        cout<<'B';
                cout<<endl;
        }
        tmp = 1;
        if(c > 50) tmp = 2;
        for(int i = 0; i < tmp; i++){
                for(int j = 0; j < 50; j++)
                        cout<<'C';
                cout<<endl;
        }
        tmp = 1;
        if(d > 50) tmp = 2;
        for(int i = 0; i < tmp; i++){
                for(int j = 0; j < 50; j++)
                        cout<<'D';
                cout<<endl;
        }

        return 0;
}
