#include <bits/stdc++.h>

using namespace std;

void walk(const vector<int>& link, vector<bool>& marked, int node){
    marked[node] = true;
    if(marked[link[node]])
        return;
    walk(link, marked, link[node]);
    cout<<node+1<<" "<<link[node]+1<<endl;
}

int main()
{
    int n; cin>>n;
    vector<int> link(n), in_degree(n);
    for(auto& iter:link){
        cin>>iter; --iter;
        ++in_degree[iter];
    }
    vector<bool> marked(n);
    vector<int> order(n); iota(order.begin(), order.end(), 0);
    partition(order.begin(), order.end(), [&](const int a){return in_degree[a] == 0;});
    for(auto&& iter:order)
        walk(link, marked, iter);
    return 0;
}
