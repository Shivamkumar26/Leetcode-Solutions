class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int freq=0, j=0;
        for(int i=0; i<nums.size(); i++) {
            if(i==0 || nums[i]==nums[i-1] && freq<2) {
                freq++;
                nums[j++]=nums[i];
            }
            else if(nums[i]==nums[i-1]) continue;
            else {
                freq=1;
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};