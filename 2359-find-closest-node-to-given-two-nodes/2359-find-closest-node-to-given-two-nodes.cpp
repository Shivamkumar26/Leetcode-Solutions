class Solution {
    void dfs(int node, vector<int>& dist, vector<int>& vis, vector<int> adj[], int d) {
        vis[node] = 1;
        dist[node] = d;
        for(int &child : adj[node]) {
            if(vis[child] == 1) continue;
            dfs(child, dist, vis, adj, d+1);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        //making adjacent connection
        for(int i = 0; i < n; i++)
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        
        vector<int> dist1(n, INT_MAX),  dist2(n, INT_MAX); 
        vector<int> vis1(n, 0),         vis2(n, 0);
        
        //simple dfs call
        dfs(node1, dist1, vis1, adj, 0);
        dfs(node2, dist2, vis2, adj, 0);   
        
        //finding max ko minimize
        int ans = INT_MAX, node = -1;
        for(int i = 0; i < n; i++) {
            if(max(dist1[i], dist2[i]) < ans) {
                ans = max(dist1[i], dist2[i]);
                node = i;
            }
        }
        return node;
    }
};