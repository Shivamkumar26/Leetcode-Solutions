class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int buy = nums[0], sell = nums[0], ans = 0;
        for(int i=1; i<nums.size(); i++) {
           if(nums[i] < buy) {
               ans = max(ans, sell-buy);
               buy = nums[i];
               sell = nums[i];
           }
           sell = max(sell, nums[i]);
           ans = max(ans, sell-buy);
        }
        return ans > 0 ? ans : 0;
    }
};