class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, l = 0;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > k) {
                while(mp[nums[i]] > k) {
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0) mp.erase(nums[l]);
                    l++;
                }
            }
            else ans = max(ans, i-l+1);
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};
/*


1-2
2-3
3-2

6


*/