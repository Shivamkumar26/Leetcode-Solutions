class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        for(int i = 0; i < m; i++) {
            int val = nums[0][i], j = 0, k = i;
            while(k < m && j < n) {
                if(nums[j][k] != val) {
                    return false;
                }
                j++; k++;
            }
        }
        for(int i = 1; i < n; i++) {
            int val = nums[i][0], j = 0, k = i;
            while(k < n && j < m) {
                if(nums[k][j] != val) {
                    return false;
                }
                j++; k++;
            }
        }
        return true;
    }
};