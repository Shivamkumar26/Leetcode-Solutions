class Solution {
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for(auto i:adj[node]) {
            if(vis[i]==0) {
                dfs(i, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && isConnected[i][j]==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;
        for(int i=0; i<n; i++) {
            if(vis[i]==0) {
                count++;
                dfs(i, adj, vis);
            }
        }
        return count;
    }
};