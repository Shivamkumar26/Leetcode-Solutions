class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int mx = INT_MIN, n = nums.size();
        vector<long long> a;
        long long t = 0;
        
        for(int i=0; i<n; i++) {
            mx = max(mx, nums[i]);
            t = (mx + nums[i]);
            a.push_back(t + (a.size() ? a[a.size()-1] : 0 ));
        }
        return a;
    }
};
/*
nums = [2,3,7,5,10]
Output: [4,10,24,36,56]
Explanation: 
For the prefix [2], the conversion array is [4] hence the score is 4
For the prefix [2, 3], the conversion array is [4, 6] hence the score is 10
For the prefix [2, 3, 7], the conversion array is [4, 6, 14] hence the score is 24
For the prefix [2, 3, 7, 5], the conversion array is [4, 6, 14, 12] hence the score is 36
For the prefix [2, 3, 7, 5, 10], the conversion array is [4, 6, 14, 12, 20] hence the score is 56
*/