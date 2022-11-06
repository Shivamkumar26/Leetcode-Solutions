class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long sum = 0, mx = 0;
        for(int i=0; i<k; i++) {
            mp[nums[i]]++;
            sum += nums[i];
        }
        if(mp.size() == k) mx = max(sum, mx);

        for(int i = 0; i < n - k; i++) {
            mp[nums[k+i]]++;
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
            sum = sum - nums[i] + nums[k+i];
                        if(mp.size() == k) mx = max(sum, mx);

            //cout << sum << endl;
        }
        return mx;
    }
};

/*

[1,1,1,7,8,9]
3
[3,5,3,4]
2
*/