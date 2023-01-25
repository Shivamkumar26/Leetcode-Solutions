class Solution {
public:
    void dfs(int i, vector<int> &dist ,vector<int> &vis,vector<int> adj[],int dis){
        vis[i]=1;
        dist[i]=dis;
        for(int &child:adj[i]){
            if(vis[child]==1)continue;
            dfs(child,dist,vis,adj,dis+1);
        }
    } 
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> distn1(n,1e9), distn2(n,1e9);
        vector<int> vis1(n,0), vis2(n,0);
        dfs(node1,distn1,vis1,adj,0);
        dfs(node2,distn2,vis2,adj,0);
        int ans=1e9, node=-1;
        for(int i=0; i<n; i++){
            if(max(distn1[i],distn2[i]) < ans){
                ans = max(distn1[i],distn2[i]);
                node = i;
            }
        }
        return node;
    }
};