class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s= 0 , e=n-1;
        while(s<=e) {
            int m = (e-s)/2+s;            
            if(m+1< n && nums[m] < nums[m+1]) {
                s = m+1;
            }
            else {
                e = m-1;
            }
        }
        return s;
    }
};