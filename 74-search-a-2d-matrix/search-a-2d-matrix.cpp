class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();
        int i = 0, j = m-1;

        while(i<n && j<m) {
            if(nums[i][j] < target) i++;
            else {
                int l = 0, r = m-1;
                while(l <= r) {
                    int m = (l+r)/2;
                    if(nums[i][m] == target) return 1;
                    else if(nums[i][m] > target) r=m-1;
                    else l = m+1;
                }
                return 0;
            }
        }
        return 0;
    }
};