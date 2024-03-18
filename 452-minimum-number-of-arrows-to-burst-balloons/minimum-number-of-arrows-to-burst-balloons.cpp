class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        int n = nums.size(), res = 1;
        sort(nums.begin(), nums.end());
        int pm = nums[0][1];

        for(int i=1; i<n; i++) {
            if(pm >= nums[i][0] && pm <= nums[i][1]) {
                continue;
            }
            if(nums[i][1]<=pm) pm = nums[i][1];
            else {
                res++;
                pm = nums[i][1];
            }   
        }
        return res;
    }
};

/*


[0,6],[0,9],[2,8],[2,9],[3,8],[3,9],[3,9],[6,8],[7,12],[9,10]


*/