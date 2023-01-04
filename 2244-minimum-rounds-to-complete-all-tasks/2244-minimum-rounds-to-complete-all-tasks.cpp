class Solution {
public:
    int minimumRounds(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++) mp[nums[i]]++;
        
        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            int num = it->second;
            if(num == 1) return -1;

            ans += num/3;
            num %= 3;
            if(num) ans++;
        }
        return ans;
    }
};