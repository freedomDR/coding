#include<iostream>
#include<string>
#include<vector>

using namespace std;
int len1, len2;
string s1, s2;
vector<int> a, d;
void kmp()
{
    string new_s = s2+"#"+s1;
    a.resize(len1);
    vector<int> prefix_func(len1+len2+1, 0);
    for(int i = 1; i < new_s.size(); i++)
    {
        int j = prefix_func[i-1];
        while(j>0&&new_s[j]!=new_s[i]) j=prefix_func[j-1];
        if(new_s[j] == new_s[i]) j++;
        prefix_func[i] = j;
    }
    for(int i = 0; i < prefix_func.size(); i++)
    {
        if(prefix_func[i] == len2)
            a[i-len2+1-(len2+1)] = 1;
    }
    //cout << "kmp" << endl;
    //for(int i = 0; i < a.size(); i++)
    //    cout << a[i];
    //cout << endl;
}

void manacher()
{
    d.resize(len1);
    int l = 0, r = -1; 
    for(int i = 0; i < len1; i++)
    {
        int j = i>r?1:min(d[r-i+l], r-i+1);
        while(i-j>=0&&i+j<len1&&s1[i-j]==s1[i+j]) j++;
        d[i] = j--;
        if(i+j>r)
        {
            l = i-j;
            r = i+j;
        }
    }
    //cout << "manacher" << endl;
    //for(int i = 0; i < len1; i++)
    //    cout << d[i];
    //cout << endl;
}

void slove()
{
    /*
        d[i] k, l, r
        a_l+a_l-1+..+a_i + a_l-1+...+a_i
        a_i * (i-l+1)
        a_i*i - a_i*l + a_i
    */
    long long ans = 0;
    vector<long long> paii(len1+1), pai(len1+1);
    for(int i = 1; i <= len1; i++)
    {
        paii[i] = paii[i-1] + a[i-1]*i;
        pai[i] = pai[i-1]+a[i-1];
    }
    //for(int i = 0; i <= len1; i++) cout << paii[i] << " ";
    //cout << endl;
    //for(int i = 0; i <= len1; i++) cout << pai[i] << " ";
    //cout << endl;
    for(int i = 0; i < len1; i++)
    {
        int l=i-d[i]+1, r=i+d[i]-1-len2+1;
        l++; r++;
        if(l>r) continue;
        int mid = (l+r) >> 1; 
        ans += paii[mid]-(l==0?0:paii[l-1]) - (pai[mid]-(l==0?0:pai[l-1]))*(l==0?0:l-1);
        if(mid!=r) ans += (pai[r]-pai[mid])*(r+1) - (paii[r]-(paii[mid]));
        //cout << l << " " << r << " " << mid << " " << ans << endl;
    }
    cout << ans%(1ll<<32) << endl;
}

int main()
{
    cin >> len1 >> len2;
    cin >> s1 >> s2;
    kmp();
    manacher();
    slove();
    return 0;
}