class Solution {
    int reverse(int n) {
        int res = 0;
        while(n) {
            res = res*10 + n%10;
            n /= 10;
        }
        return res;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            s.insert(nums[i]);
            s.insert(reverse(nums[i]));
        }
        return s.size();
    }
};