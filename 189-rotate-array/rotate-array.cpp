class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n) return;
        else k%=n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};