class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int mx = 0;
        for(int i=0; i<n; i++) mp[nums[i]]++, mx=max(mx, mp[nums[i]]);
        
        vector<vector<int>> ans(mx);
        for(int i=0; i<n; i++) {
            int idx = 0;
            while(mp[nums[i]] > 0) {
                ans[idx].push_back(nums[i]);
                mp[nums[i]]--;
                idx++;
            }
        }
        return ans;
    }
};