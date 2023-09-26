class Solution {
        void solve(vector<int>& nums, int i, int sum, int& t, vector<int>& temp, vector<vector<int>>& ans) {
        if(t == sum) {
            ans.push_back(temp); 
            return; 
        }
        if(t < sum || i == nums.size()) return;

        for(int j=i; j<nums.size(); j++) {
            if(j!=i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            solve(nums, j+1, sum+nums[j], t, temp, ans); 
            temp.pop_back();
        }
            
        // solve(nums, i+1, sum, t, temp, ans);
        // temp.push_back(nums[i]);
        // solve(nums, i+1, sum+nums[i], t, temp, ans); 
        // temp.pop_back();
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, 0, 0, t, temp, ans);
        return ans;   
    }
};