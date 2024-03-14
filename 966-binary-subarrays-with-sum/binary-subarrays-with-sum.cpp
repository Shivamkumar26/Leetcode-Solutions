class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), sum = 0, count = 0;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(sum == goal) count++;
            if(mp.count(sum-goal)) count += mp[sum-goal];
            mp[sum]++;
        }
        return count;
    }
};