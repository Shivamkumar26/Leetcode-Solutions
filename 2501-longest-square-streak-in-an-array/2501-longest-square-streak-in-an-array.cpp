class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> s;
        int n=nums.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            s.insert(nums[i]);
        }
        for(int i=0; i<n; i++) {
            long long e = (long long)nums[i]*(long long)nums[i];
            int l = 1;
            while(s.find(e)!=s.end()) {
                l++;
                e = e*e;
            }
            ans = max(ans, l);
        }
        return ans < 2 ? -1 : ans;
    }
};

/***

[4,3,6,16,8,2]

2
3
4
6
8
16


***/