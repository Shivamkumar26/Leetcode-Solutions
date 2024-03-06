class Solution {
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), count = 0, sum = 0;
        
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(sum==k) count++;
            if(mp.count(sum-k)) count+=mp[sum-k];            
            mp[sum]++;
        }
        return count;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& nums, int k) {
        int r = nums.size(), c = nums[0].size();
        int ans = 0;
        
        for(int i=0; i<r; i++) {
            //going from every row
            vector<int> pre(c, 0);
            for(int j=i; j<r; j++) {
                for(int k=0; k<c; k++) {
                    pre[k] += nums[j][k];
                }
                ans += subarraySum(pre, k);
            }
        }
        return ans;
    }
};
/*

1 2
3 4

- col wise sum 
- number of subarry with sum = k 

0 1 0
1 2 1
1 3 1



*/