class Solution {
    void solve(int si, int sj, int count, int& ans, vector<vector<int>>& nums) {
        if(si < 0 || sj < 0 || si == nums.size() || sj == nums[0].size() || 
           nums[si][sj] == -1) 
            return;
        if(nums[si][sj] == 2) {
            if(count == 0) ans++;
            return;
        }
        
        nums[si][sj] = -1;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {-1, 1, 0, 0};
        for(int i=0; i<4; i++) 
            solve(si+dr[i], sj+dc[i], count-1, ans, nums);
        
        nums[si][sj] = 1;
    }
public:
    int uniquePathsIII(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int ans = 0, count = 0;
        int si = -1, sj = -1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums[i][j] == 0 || nums[i][j] == 2)
                    count++;
                else if(nums[i][j] == 1) {
                    si = i;
                    sj = j;
                    count++;
                }
            }
        }
        
        solve(si, sj, count-1, ans, nums);
        return ans;
    }
};