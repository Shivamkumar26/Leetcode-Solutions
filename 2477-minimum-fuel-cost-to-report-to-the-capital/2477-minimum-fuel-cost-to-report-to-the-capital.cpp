class Solution {
public:
    long long ans = 0; 
    
    long long dfs(vector<int>& vis, int node, int seats, vector<int> adj[]){
        vis[node] = 1; 
        long long count = 1; 
        
        for(auto it : adj[node]){
            if(!vis[it])
                count += dfs(vis, it, seats, adj);
        }
    
        long long x = count / seats;
        if(count % seats) x++;
        if(node != 0) ans += x;
        
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> adj[n+1], vis(n+1, 0);
        
        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(vis, 0, seats, adj);
        return ans; 
    }
};