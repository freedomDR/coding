#include <bits/stdc++.h>

using namespace std;
#define SIZE 9

struct Node{
    int to, weight;
};
vector<Node> edges[SIZE];

void zeroOneBFS(int start){
    int dist[SIZE];
    for(int i = 0; i < SIZE; i++) dist[i] = INT_MAX;
    deque<int> Q;
    dist[start] = 0;
    Q.push_back(start);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop_front();
        for(int i = 0; i < edges[v].size(); i++){
            if(dist[edges[v][i].to] > dist[v] + edges[v][i].weight){
                dist[edges[v][i].to] = dist[v]+ edges[v][i].weight;
                if(edges[v][i].weight == 0) Q.push_front(edges[v][i].to);
                else Q.push_back(edges[v][i].to);
            }
        }
    }
    for(int i = 0; i < SIZE; i++) cout<<dist[i]<<" ";
}

void addEdge(int u, int v, int wt){
    edges[u].push_back({v, wt});
    edges[v].push_back({u, wt});
}

int main(){
	addEdge(0, 1, 0); 
	addEdge(0, 7, 1); 
	addEdge(1, 7, 1); 
	addEdge(1, 2, 1); 
	addEdge(2, 3, 0); 
	addEdge(2, 5, 0); 
	addEdge(2, 8, 1); 
	addEdge(3, 4, 1); 
	addEdge(3, 5, 1); 
	addEdge(4, 5, 1); 
	addEdge(5, 6, 1); 
	addEdge(6, 7, 1); 
	addEdge(7, 8, 1);
    zeroOneBFS(0);
    return 0;
}
