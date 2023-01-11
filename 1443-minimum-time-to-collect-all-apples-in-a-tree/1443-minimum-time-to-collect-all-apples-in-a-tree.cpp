class Solution {
    pair<int, int> solve(int child, int par, vector<bool>& hasApple, vector<int> adj[]) {
        pair<int, int> v = {0, hasApple[child]};
        
        for(auto i : adj[child]) {
            if(i == par) continue;
            auto x = solve(i, child, hasApple, adj);
            v.first += (2 + x.first) * x.second;
            v.second |= x.second;
        }
        return v;
    }
    
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(int i=0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return solve(0, 0, hasApple, adj).first;
    }
};