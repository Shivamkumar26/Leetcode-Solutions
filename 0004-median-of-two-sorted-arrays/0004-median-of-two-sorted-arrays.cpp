class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while(i<n && j < m) {
            if(nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i++]);
            } else {
                nums.push_back(nums2[j++]);
            }
        }
        while(i<n) nums.push_back(nums1[i++]);
        while(j<m) nums.push_back(nums2[j++]);

        if((n+m)%2) return (double)nums[(n+m)/2];
        return (double)(nums[(n+m-1)/2] + nums[(n+m)/2])/2.0; 
    }
};

/*

if m+n length = odd
ans = sorted (m+n)/2th ele

else 
ans = sorted (m+n)/2 + (m+n)/2+1

store in sorted manner

*/