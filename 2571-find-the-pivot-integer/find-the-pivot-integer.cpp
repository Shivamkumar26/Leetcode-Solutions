class Solution {
public:
    int pivotInteger(int n) {
        vector<int> nums(n+1, 0);
        for(int i=1; i<=n; i++) nums[i] = i+nums[i-1];
        long long sum = (n*(n+1))/2;
        int res = -1;
        for(int i=1; i<=n; i++) {
            if(nums[i] == sum - nums[i-1]) return i;
        }
        return res;
    }
};