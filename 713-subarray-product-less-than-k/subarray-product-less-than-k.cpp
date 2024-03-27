class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        long long prod = 1;
        int ans = 0;

        if(k<=1) return 0;
        while(r < n) {
            prod*=nums[r];
            while(prod>=k) {
                prod/=nums[l++];
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};
/*

10 50 100 600


3
10 


*/