class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), l=0, r=0;
        while(r < n && nums[r] < 0) r++;
        l = r-1;
        while(l >=0 && r < n) {
            if(nums[l]*nums[l] > nums[r]*nums[r]) {
                ans.push_back(nums[r]*nums[r]);
                r++;
            } else { 
                ans.push_back(nums[l]*nums[l]);
                l--;
            }
        }
        while(l >= 0) ans.push_back(nums[l]*nums[l--]);
        while(r < n) ans.push_back(nums[r]*nums[r++]);
        return ans;
    }
};
/*

-4 -1 0 3 10

l -1 (l--) (while l>=0)
r 3 (r++) (while r < size)


0 1 


*/