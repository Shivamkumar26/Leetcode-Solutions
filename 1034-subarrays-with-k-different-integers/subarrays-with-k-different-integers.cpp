class Solution {
    int countSmallerK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), l = 0, count = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp.size() < k) ans += (i-l+1);
            else if(mp.size() == k) {
                while(mp.size() == k) {
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) mp.erase(nums[l]);
                    l++;
                }
                ans += (i-l+1); 
            }
        }
        return ans;
    }
    int countGreaterK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), l = 0, ans = 0;

        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
            if(mp.size() > k) {
                while(mp.size() > k) {
                    ans += (n-i);
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0) mp.erase(nums[l]);
                    l++;
                }
            }
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return countGreaterK(nums, k-1) - countGreaterK(nums, k);
    }
};
/*

ans = total subarray - subarray < k - subarray > k
1 2 1

*/