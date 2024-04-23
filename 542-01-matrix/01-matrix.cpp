class Solution {
    void bfs(vector<vector<int>>& res, vector<vector<int>>& nums, vector<vector<int>>& vis, int n, int m) {
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
        if(nums[i][j]!=1) { 
            q.push({{i, j}, 0});
            vis[i][j]=1;
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while(q.size()) {
            int r = q.front().first.first, c = q.front().first.second;
            int dis = q.front().second;

            res[r][c] = dis;
            q.pop();

            for(int k=0; k<4; k++) {
                int nr = r+dr[k], nc = c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0) {
                    q.push({{nr, nc}, dis+1});
                    vis[nr][nc]=1;
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<vector<int>> res(n, vector<int>(m, 0));
        bfs(res, nums, vis, n, m);
        return res;
    }
};