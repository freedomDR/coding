#include <bits/stdc++.h>

using namespace std;


int main()
{
    int M, N;
    cin>>M>>N;
    deque<int> s;
    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        int temp, j;cin>>temp;
        for(j = 0; j < s.size(); j++)
        {
            if(s[j] == temp) break;
        }
        if(j == s.size())
        {
            ans++;
            s.push_back(temp);
            if(s.size() == M+1) s.pop_front();
        }
    }
    cout<<ans<<endl;
    return 0;
}
