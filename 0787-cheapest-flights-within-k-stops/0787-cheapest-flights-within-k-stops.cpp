class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto i: flights) adj[i[0]].push_back({i[1], i[2]});
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{src, 0}, k});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while(!q.empty()) {
            int node = q.front().first.first;
            int dis = q.front().first.second; 
            int stops = q.front().second;
            q.pop(); if(stops < 0) continue;
            
            for(auto it: adj[node])
                if(dis + it.second < dist[it.first]) {
                    dist[it.first] = dis + it.second;
                    q.push({{it.first, dist[it.first]}, stops-1});
                }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};