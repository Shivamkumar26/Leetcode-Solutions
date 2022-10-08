class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            
            int l = i+1, r = n-1;
            while (l<r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) return sum;
                if(abs(target - ans) > abs(target - sum))
                    ans = sum;
                if(sum < target) l++;
                else r--;
                while (l<r && nums[l]==nums[l-1]) l++;
                while (l<r && r<n-1 && nums[r]==nums[r+1]) r--;
            }
        }
        return ans;
    }
};