class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        int s = 0, maxLen = 0;
        for(int e = 0; e < nums.size(); e++) {
            mp[nums[e]]++;
            maxLen = max(maxLen, mp[nums[e]]);

            int maxDiff = e-s+1-maxLen;
            if(maxDiff > k) {
                mp[nums[s]]--;
                s++;
            }
        }
        return maxLen;
    }
};

/*
[1,1,2,2,1,1]
[1,4,2,3,6,4,4,6,2,3,5,1,3,5,4,2]
5

 


*/