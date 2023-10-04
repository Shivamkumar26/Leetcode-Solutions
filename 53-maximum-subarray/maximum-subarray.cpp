class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxtillnow = nums[0], currsum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            currsum = max(currsum + nums[i], nums[i]);
            maxtillnow = max(maxtillnow, currsum);
        }
        return maxtillnow;
    }
};