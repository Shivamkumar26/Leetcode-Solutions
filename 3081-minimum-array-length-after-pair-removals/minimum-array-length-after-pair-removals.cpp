class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        //if(nums.size()==1) return 1;
        int mx = 0, n = nums.size(), freq = 0;
        for(int i=0; i<n; i++) {
            if(i==0 || nums[i]==nums[i-1]) freq++, mx = max(mx, freq);
            else freq = 1;
        }
        
        if(mx <= n/2) return n%2 ? 1 : 0;
        return n - (n-mx)*2;
    }
};
/*

1 1 1 1 1 2 3
(7 - 5)*2

1 1 1 2 2 2 4 5 6 9
l r

max equal elements



*/