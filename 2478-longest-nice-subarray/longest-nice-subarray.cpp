class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 1, len = 1, mx = 1, orr = nums[0]; 

        while(r < n) {
            while(r < n && (nums[r] & orr) == 0) {
                len++;
                orr |= nums[r];
                r++;
            }
            mx = max(mx, len);
            while(r < n && (nums[r] & orr) != 0) {
                orr ^= nums[l++];
                len--;
            }
        }
        return mx;
    }
};