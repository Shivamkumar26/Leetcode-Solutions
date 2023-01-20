class Solution {
    void solve(int i, vector<int> temp, set<vector<int>>& allans, vector<int>& nums) {
        if(i == nums.size()) return;
        
        solve(i+1, temp, allans, nums);
        
        if(temp.size()==0 || nums[i] >= temp.back()) {
            temp.push_back(nums[i]);
            if(temp.size() > 1) 
                allans.insert(temp);
            
            solve(i+1, temp, allans, nums);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        set<vector<int>> allans;
        
        solve(0, temp, allans, nums);
        for(auto i:allans)
            ans.push_back(i);
        return ans;
    }
};