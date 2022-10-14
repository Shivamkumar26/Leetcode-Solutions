class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& nums)
    {
        int n = nums.size();
        vector<int> row(n);
        vector<int> col(n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                col[i] = max(col[i], nums[i][j]);
                row[i] = max(row[i], nums[j][i]);
            }
        }
        
        int ans = 0;
       for(int i=0; i<n; i++) {
           for(int j=0; j<n; j++) {
               ans += (min(row[j], col[i])-nums[i][j]);
           }
       }
    return ans;
    }
};