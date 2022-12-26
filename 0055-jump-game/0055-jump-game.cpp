class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int jump = 0;
        for(int i=0; i<n-1; i++) {
            jump = max(jump, nums[i]+1);
            jump--;
            if(jump == 0 && nums[i] == 0)
                return false;
        }
        return true;
    }
};