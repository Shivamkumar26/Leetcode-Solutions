class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int n = nums.size(), sum = 0;
        mp[0]=-1;
        for(int i=0; i<n; i++) {
            // sum = (sum + nums[i])%k;
        sum+=nums[i];
            if(mp.count(sum%k)) {
                if(i-mp[sum%k] > 1) return 1;
            }
            else mp[sum%k]=i;
        }
        return false;
    }
};

/*


[23,2,4,6,6]
7

2
4
1
0
0


5
1
5

5
1
5


*/