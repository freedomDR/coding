class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> visit(graph.size(), 0);
        path.push_back(0);
        dfs(graph, 0, visit);
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, int st, vector<int>& visit) {
        if(st == graph.size()-1) {
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < graph[st].size(); i++) {
            if(visit[graph[st][i]] == 0) {
                visit[graph[st][i]] = 1;
                path.push_back(graph[st][i]);
                dfs(graph, graph[st][i], visit);
                path.pop_back();
                visit[graph[st][i]] = 0;
            }
        }
    }
};
