#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n, k, s;
        cin>>n>>k;
        map<int, int> a;
        for(int i = 0; i < n; i++){
                int tmp;
                cin>>tmp;
                if(a.find(tmp) == a.end()) a.insert(make_pair(tmp, i+1));
        }
        if(a.size() >= k){
                cout<<"YES"<<endl;
                auto j = a.begin();
                for(int i = 0; i < k; i++, j++)
                        cout<<j->second<<" ";
        }else{
                cout<<"NO"<<endl;
        }
        return 0;
}
