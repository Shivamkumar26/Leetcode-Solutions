class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i>=0 && nums[i]==9) {
            i--;
        }
        
        if(i==-1) {
            vector<int> ans(n+1);
            ans[0] = 1;
            return ans;
        }
        
        nums[i] += 1;
        i++;
        for(; i<n; i++) nums[i] = 0;
        return nums;
    }
};