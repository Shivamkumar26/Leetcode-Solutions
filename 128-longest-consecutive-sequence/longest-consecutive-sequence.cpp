class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) mp[nums[i]] = 1;

        int ans = 0;
        for(int i=0; i<n; i++) {
            int count = 0;
            if(mp.find(nums[i]-1) != mp.end()) continue;
            else {
                while(mp.find(nums[i])!=mp.end() && mp[nums[i]]) {
                    count++;
                    mp[nums[i]] = 0;
                    nums[i]++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};