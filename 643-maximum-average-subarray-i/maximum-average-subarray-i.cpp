class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double run = 0, res = INT_MIN;
        int n = nums.size(), r = 0, kk = k;
        while(kk--) {
            run += nums[r];
            r++;
        }

        for(int i=0; i<n-k; i++) {
            res = max(res, (double)run/(double)k);
            run -= nums[i]; 
            run += nums[i+k];           
        }
        return max(res, run/(double)k);
    }
};