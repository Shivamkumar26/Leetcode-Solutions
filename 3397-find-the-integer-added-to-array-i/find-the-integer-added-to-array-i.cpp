class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int mx = *max_element(nums1.begin(), nums1.end());
        int mx2 = *max_element(nums2.begin(), nums2.end());

        return mx2-mx;
    }
};
/*

2 6 4

5 7 9


2 5



*/