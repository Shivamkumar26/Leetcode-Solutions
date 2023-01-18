class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), sum = nums[0];
        int maxSub = nums[0], currmax = nums[0];
        int minSub = nums[0], currmin = nums[0];
        
        for(int i=1; i<n; i++) {
            sum += nums[i];
            currmax = max(currmax + nums[i], nums[i]);
            maxSub = max(maxSub, currmax);
            
            currmin = min(currmin + nums[i], nums[i]);
            minSub = min(minSub, currmin);
        }
        if(sum == minSub) return maxSub;
        return max(maxSub, sum-minSub);
    }
};