class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) s.insert(nums[i]);
        }
        int ans = 1;
        while(s.size()) {
            auto it = s.begin();
            int e = *it;
            if(e==ans) {
                ans++;
            } else break;
            s.erase(it);
        }
        return ans;
    }
};
/*

1 2

3 4 1




*/