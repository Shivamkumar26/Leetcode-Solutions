class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        // and value = min val
        // 1 2 and = 0 1,3,4
        int ans = 0, n = nums.size();
        int c = INT_MAX;
        for(int i=0; i<n; i++) {
            c = c & nums[i];
        }
        if(c!=0) return 1;
        c = INT_MAX;
        for(int i=0; i<n; i++) {
            c = c & nums[i];
            if(c==0) {ans++; c = INT_MAX;}
        }
        return ans;
    }
};