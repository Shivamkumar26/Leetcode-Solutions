class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, res = n+1, sum = 0;
        while(r < n) {
            while(r < n && sum < k) {
                sum += nums[r++];
            }
            if(sum >= k) res = min(res, r-l);
            while(sum >= k) {
                sum -= nums[l++];
                if(sum >= k) res = min(res, r-l);
            }
        }
        return res == n+1 ? 0 : res;
    }
};