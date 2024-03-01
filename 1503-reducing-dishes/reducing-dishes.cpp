class Solution {
    int solve(vector<int>& nums, int st) {
        int ans = 0;
        int k = 1;
        for(int i=st; i<nums.size(); i++) 
            ans += (nums[i]*(k++));
        return ans;
    }
public:
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[n-1] < 0) return 0;
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(solve(nums, i), ans);
            if(nums[i]>0) break;
        }
        return ans;
    }
};