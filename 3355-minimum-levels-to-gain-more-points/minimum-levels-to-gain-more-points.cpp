class Solution {
public:
    int minimumLevels(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n, 0);
        for(int i=n-1; i>=0; i--) {    
            if(nums[i]==0) nums[i]=-1;
            if(i==n-1) suff[i]=nums[i];
            else suff[i] = suff[i+1]+nums[i];
        }

        int pre = nums[0], c = 1;
        for(int i=0; i<n-1; i++) {
            if(pre > suff[i+1]) {
                break;
            }
            pre += nums[i+1];
            c++;
        }
        return c==n ? -1 : c;
    }
};
/*

prefix > suffix


*/