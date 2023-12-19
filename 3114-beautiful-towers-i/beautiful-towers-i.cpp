class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            int top = nums[i], l = nums[i], r = nums[i], li = i-1, ri = i+1;
            long long sum = nums[i];
            
            while(li>=0) {
                l = min(l, nums[li]);
                sum += l;
                li--;
            }
            
            while(ri<n) {
                r = min(r, nums[ri]);
                sum += r;
                ri++;
            }
            ans = max(ans, sum);
        }
        
        return ans;
    }
};