class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& ni) {
        vector<vector<int>> ans;

        int i=0, n = nums.size();
        while(i<n && nums[i][1] < ni[0]) {
            ans.push_back(nums[i]);
            i++;
        }

        while(i<n && nums[i][0] <= ni[1]) {
            ni[0] = min(ni[0], nums[i][0]);
            ni[1] = max(ni[1], nums[i][1]);
            i++;
        }
        ans.push_back(ni);
        while(i<n) {
            ans.push_back(nums[i++]);
        }
        return ans;
    }
};