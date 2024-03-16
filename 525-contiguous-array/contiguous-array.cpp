class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), len = 0, sum = 0;
        mp[0] = -1;
        for(int i=0; i<n; i++) {
            sum += (nums[i]==0 ? -1 : 1);
            if(sum == 0) len = i+1;
            if(mp.count(sum)) {
                len = max(len, i-mp[sum]);
            } else mp[sum]=i;
        }
        return len;
    }
};

/*

0011110

-1 -2 -1 0 1 2 1  

one - 4
zero - 3

*/