#include<iostream>
#include<vector>
#include<string>

using namespace std;

string s1, s2; 

void kmp()
{
    string new_s = s2+"#"+s1;
    vector<int> prefix_func(new_s.size());
    for(int i = 1; i < new_s.size(); i++)
    {
        int j = prefix_func[i-1];
        while(j>0&&new_s[j]!=new_s[i]) j=prefix_func[j-1];
        if(new_s[i]==new_s[j]) j++;
        prefix_func[i] = j; 
    }
    cout << new_s << endl;
    for(auto v:prefix_func) cout << v << " ";
    cout << endl;
}

int main()
{
    cin >> s1 >> s2;
    kmp();
    return 0;
}