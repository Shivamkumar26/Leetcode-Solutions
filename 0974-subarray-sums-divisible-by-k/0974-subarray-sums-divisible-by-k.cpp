class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        
        for(int i=0; i<n; i++) {
            if(i==0) pre[i] = nums[i];
            else pre[i] = pre[i-1] + nums[i];
        }
        
        int ans = 0;        
        unordered_map<int, int> mp;
        mp[0]++;
        
        for(int i=0; i<n; i++) {
            pre[i]%=k;
            if(pre[i] < 0) pre[i]+=k;
            mp[pre[i]]++;
            if(mp[pre[i]] > 1) ans+=mp[pre[i]]-1;
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