class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = INT_MIN, run = 1;
        
        for(int i=0; i<n; i++) {
            run *= nums[i];
            if(prod < run) prod = run;
            if(run == 0) run = 1;
        }
        run = 1;
        for(int i = n-1; i >= 0; i--) {
            run *= nums[i];
            if(prod < run) prod = run;
            if(run == 0) run = 1;
        }
        return prod;
    }
};
/*
[-1,-2,-3,0]
[-3,9,8,0,-2]

*/