class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[prev] == nums[i]) continue;
            else {
                prev++;
                nums[prev] = nums[i];
            }
        }
        return prev+1;
    }
};