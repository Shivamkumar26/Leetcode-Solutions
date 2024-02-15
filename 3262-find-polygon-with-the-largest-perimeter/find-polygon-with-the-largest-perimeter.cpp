class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        
        int i = n-1;
        while(i>=2) {
            if(sum-nums[i] > nums[i]) break;
            else sum -= nums[i--];
        }
        
        return i < 2 ? -1 : sum;
    }
};
/*

sort nums 
largest ele < sum of all other -> true sum + largest
else sum 


*/