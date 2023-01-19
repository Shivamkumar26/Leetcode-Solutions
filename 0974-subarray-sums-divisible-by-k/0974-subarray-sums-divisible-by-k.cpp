class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;        
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        
        for(int i=0; i<n; i++) {
            sum += nums[i];
            int rem = sum%k;
            if(rem < 0) rem+=k;
            mp[rem]++;
            if(mp[rem] > 1) ans+=mp[rem]-1;
        }
        
        return ans;
    }
};

/**

k=4
[4,5,0,-2,-3,1,45,90,-9,-9,-8]

4 9 9 7 4 5 50 140 131 122 114
4 4 4 2 4 0 0  0    1    2   4 

1+2+3+4+6




k=5
4 5 0 -2 -3 1 

4 9 9  7  4 5 
4 4 4  2  4 0 

1 + 2 + 3 + 1 

**/