class Solution {
    void dfs(int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = 1;
        bool ans = false;
        for(auto it: adj[node]) {
            if(vis[it]==0) dfs(it,  adj, vis);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        int m = edges.size();
        for(int i=0; i<m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, 0);
        dfs(source, adj, vis);
        return vis[destination];
    }
};