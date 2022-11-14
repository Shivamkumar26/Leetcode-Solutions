class Solution {
    void dfs(vector<vector<int>>& stones, vector<bool>& visited, int ind, int n) {
        visited[ind] = true;
        for(int i=0; i<n; i++)
            if(!visited[i] && (stones[ind][0]==stones[i][0] || stones[ind][1]==stones[i][1])) 
                dfs(stones, visited, i, n);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), ans = n;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(stones, visited, i, n);
                ans--;
            }
        }
        return ans;
    }
};