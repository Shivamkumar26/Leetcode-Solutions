class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), sum=nums[0], mx=nums[0];
        for(int i=1; i<n;i++) {
            sum = max(nums[i], sum+nums[i]);
            mx = max(sum, mx);
        }
        return mx;
    }
};

/*

-2 1 -3 4 -1 2 1 -5 4

s=5
m=6

sum = max(cur-ele, sum+cur-ele)
mx = max(sum, mx)

*/