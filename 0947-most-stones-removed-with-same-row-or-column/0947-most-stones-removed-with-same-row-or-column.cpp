class Solution {
    void dfs(vector<vector<int>>& stones, vector<bool>& visited, int ind, int n) {
        visited[ind] = true;
        for(int i=0; i<n; i++)
            // if any row or col has same i, ind val that means they are in same row so call dfs and make them visited as well.
            if(!visited[i] && (stones[ind][0]==stones[i][0] || stones[ind][1]==stones[i][1])) 
                dfs(stones, visited, i, n);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), ans = n;
        vector<bool> visited(n, false); 
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) { // visited array
                dfs(stones, visited, i, n); // counting island and reducing ans
                ans--;
            }
        }
        return ans;
    }
};