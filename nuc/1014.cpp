#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char s[20], start;
    cin>>n;
    start = 'Z';
    for(int i = 1; i <= 2*n-1; i++){
        for(int j = 0; j < 19; j++)
            s[j] = ' ';
        s[19] = '\0';
        int mid = i;
        if(mid > n)
            mid = 2*n - mid;
        mid--;
        int l = n-mid-1;
        int r = n+mid-1;
        s[l] = start;
        start -= 1;
        if(l == r)
            start += 1;
        s[r] = start;
        start -= 1;
        for(int j = 0; j < 19; j++){
            cout<<s[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
