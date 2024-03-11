class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long sum = 0;
        sort(nums.rbegin(), nums.rend());
        for(int i=0; i<k; i++) {
            int num = nums[i]-i;
            if(num > 0) sum+=num;
        }
        return sum;
    }
};