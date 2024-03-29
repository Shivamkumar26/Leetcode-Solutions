class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, 
        mx = *max_element(nums.begin(), nums.end()), count = 0;
        long long ans = 0;

        for(int i=0; i<n; i++) {
            if(nums[i]==mx) count++;
            if(count >= k) {
                while(count >= k) {
                    ans += (n-i);
                    if(nums[l]==mx) count--;
                    l++;
                }
            }
        }
        return ans;
    }
};
/*

smaller than k times

2 * 2


*/