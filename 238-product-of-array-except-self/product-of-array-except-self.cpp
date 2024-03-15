class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pre, suf(n);

        for(int i=0; i<n; i++) {
            if(i==0) pre.push_back(nums[i]);
            else pre.push_back(nums[i]*pre[i-1]);
        }

        for(int i=n-1; i>=0; i--) {
            if(i==n-1) suf[n-1] = nums[n-1];
            else suf[i] = nums[i]*suf[i+1];
        }

        for(int i=0; i<n; i++) {
            if(i==0) ans[i] = suf[1];
            else if(i==n-1) ans[i] = pre[n-2];
            else {
                ans[i] = pre[i-1]*suf[i+1];
            }
        }
        return ans;
    }
};