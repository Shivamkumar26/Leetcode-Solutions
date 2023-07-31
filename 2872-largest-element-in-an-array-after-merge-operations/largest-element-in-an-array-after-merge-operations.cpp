class Solution {
public:
    
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=n-1; i>=0; i--) {
            if(nums[i] <= sum) sum += nums[i];
            else sum = nums[i];
        }
        return sum;
    }
};

/*

ans = 29

1  2  3  4  1  6  10  12  2  3
1  3  6 10  1  7  17  29  2  3 

ans = 39, li = 8


ans = 29
1  2  3  4  2  1  6  10  12  2  3
1  3  6 10  2  1  7  17  29  2  3 
ans = 29

*/