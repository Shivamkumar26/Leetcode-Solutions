class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int s = 0, e = nums.size()-1;
        while(s <= e) {
            int m = (e-s)/2 + s;
            if(nums[m] == tar) return m;
            if(nums[m] > tar) e = m-1;
            else s = m+1;
        }
        return -1;
    }
};