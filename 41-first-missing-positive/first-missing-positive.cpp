class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]>0 && nums[i]<=n) {
                int a = nums[nums[i]-1], b=nums[i];
                swap(nums[nums[i]-1], nums[i]);
                if(a!=b)
                i--;
            }
        }
        for(int i=0; i<n; i++) {
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
/*

1 -1 3 4


to avoid tle - 
case when element is at correct place already.
it does i-- -> infinite loop
if(a!=b) i--;


3 4 5 1
5 3 

*/