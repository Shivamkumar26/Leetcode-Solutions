class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cs = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) ans+=(++cs);
            else cs = 0;
        }
        return ans;
    }
};