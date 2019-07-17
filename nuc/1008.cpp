#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
vector<int> mid;
int maxx = 100000000;
int depth = 0;

int gcd(int a, int b){
    if(a%b == 0)
        return b;
    return gcd(b,a%b);
}

int  slove(int a, int b, int pos, int d)
{
    if(a == 0){
        cout<<"ok"<<endl;
        for(vector<int>::iterator it = mid.begin(); it != mid.end(); ++it){
            cout<<*it<<" ";
        }
        cout<<endl;
        if(ans.empty()){
            vector<int> mmid (mid);
            ans.swap(mmid);
            depth = ans.size();
        }
        if(ans.back() > mid.back()){
            vector<int> mmid (mid);
            ans.swap(mmid);
        }
        maxx = ans.back();
        return 0;
    }
    if(d == depth)
        return 0;
    //cout<<"+"<<ans.size()<<"+"<<mid.size()<<endl;
    //if(ans.size() != 0 && ans.size() == mid.size()){
    //    cout<<"lenth is larger"<<endl;
    //    return 1;
    //}
    for(int i = pos; i <= maxx; i++){
        float m = float(b)/a;
        if(m > float(i))
            continue;
        if(a*i >= b*(depth - d + 1) || (!ans.empty() && maxx*a < b))
            break;
        int mm = gcd(b, i);
        int aa = a*i/mm - b/mm, bb = b*i/mm;
        mm = gcd(aa,bb);
        aa /= mm;
        bb /= mm;
        mid.push_back(i);
        slove(aa, bb, i+1, d+1);
        mid.pop_back();
    }
}


int main()
{
    int a, b, n;
    scanf("%d", &n);
    while(n--){
        ans.clear();
        mid.clear();
        maxx = INT_MAX;
        scanf("%d %d", &a, &b);
        int pos = 2;
        depth = INT_MAX;
        slove(a,b,pos, 0);
        for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
}
