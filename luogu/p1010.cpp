#include<bits/stdc++.h>
using namespace std;

string slove(int n) {
    if(n <= 2) return to_string(n);
    string ans = "";
    int t = 0;
    while(n > 0) {
        if(n & 1) 
            ans = "2" + (t==1?"":("(" + slove(t) + ")"))+"+" + ans;
        n >>= 1;
        t++;
    }
    return ans.substr(0, ans.size()-1);
}

int main()
{
    int n;
    cin >> n;
    string ans = slove(n);
    cout << ans << endl;
    return 0;
}
