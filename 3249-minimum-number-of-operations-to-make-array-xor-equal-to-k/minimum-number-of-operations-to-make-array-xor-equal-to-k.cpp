class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        long long xxor = 0;
        for(int i=0; i<n; i++) {
            xxor ^= nums[i];
        }

        int count = 0;
        for(int i=0; i<32; i++) {
            if(((k >> i) & 1) != ((xxor >> i) & 1))
            count++;
        }
        return count;
    }
};
/*

2^1^3^4

 10
 01
 11
100
---
100

4 -> 1
100
001

*/