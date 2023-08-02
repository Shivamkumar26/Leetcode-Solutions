class Solution {
    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return; 
        }

        for(int i=ind; i<nums.size(); i++) {
            swap(nums[i], nums[ind]);
            solve(ind+1, nums, ans);
            swap(nums[i], nums[ind]);
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};

/*

1,2,3   1,3,2 
2,1,3   2,3,1
3,2,1   3,1,2

0,0 - (0,(n-1))
results add
1,1


*/