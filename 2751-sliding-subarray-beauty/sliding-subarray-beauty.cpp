class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mp;
        int lt = 0;

        for (int i = 0; i < k; i++) {
            if (nums[i] < 0) mp[nums[i]]++;
        }

        for(int i=k-1; i<n; i++) {
            int order = 0, ele = 0;
            for(auto it = mp.begin(); it!=mp.end(); it++) {
                order += it->second;
                if(order >= x) {
                    ele = it->first;
                    break;
                }
            }
            ans.push_back(ele);

            if(i<n-1) {
                if (nums[i + 1] < 0) mp[nums[i + 1]]++;
                if (nums[lt] < 0) mp[nums[lt]]--;
                if (mp[nums[lt]] == 0) mp.erase(nums[lt]);
                lt++;
            }
        }
        return ans;
    }
};