class Solution {
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
        
        queue<int> q;
        vector<int> vis(n, 0);
        int no_of_cities = 0;
        
        for(int i=0; i<n; i++) {
            if(vis[i]==0) {
                q.push(i);
                vis[i]=1;
                no_of_cities++;

                while(q.size()) {
                    int node = q.front();
                    q.pop();

                    for(auto it : adj[node]) {
                        if(!vis[it]) {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        return no_of_cities;
    }
};