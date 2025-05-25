class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r) {
            int m = (r-l)/2+l;

            if(target == nums[m]) return m;

            else if(nums[l] <= nums[m]) {
                if(target >= nums[l] && target < nums[m]) r = m-1;
                else l = m+1;
            }
            else {
                if(target <= nums[r] && target > nums[m]) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};