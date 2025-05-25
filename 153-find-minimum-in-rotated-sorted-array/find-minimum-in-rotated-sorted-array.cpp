class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n-1;

        int ans = INT_MAX;
        while(l <= r) {
            int mid = (r-l)/2 + l;
            if(nums[mid] < ans) ans = nums[mid];

            //left sorted 
            if(nums[l] <= nums[mid]) {
                ans = min(ans, nums[l]);
                l = mid+1;
            }
            //right sorted
            else {
                r = mid-1;
            }
        }
        return ans;
    }
};