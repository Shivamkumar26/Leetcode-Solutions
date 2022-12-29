class Solution {
    void dfs(int i, vector<int> adj[], vector<int>& vis) {
        vis[i] = 1;
        for(auto it: adj[i]) {
            if(vis[it] == 0)
            dfs(it, adj, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& adjm) {
        //adj matrix is given 
        int v = adjm.size();
        vector<int> adj[v];
        for(int i=0; i<v; i++) {
            for(int j=0; j<v; j++) {
                if(adjm[i][j] != 0 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        vector<int> vis(v, 0);
        for(int i=0; i<v; i++) {
            if(vis[i] == 0) {
                dfs(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
};