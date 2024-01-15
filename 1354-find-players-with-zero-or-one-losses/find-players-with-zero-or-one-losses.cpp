class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            if(mp.find(nums[i][0])==mp.end()) mp[nums[i][0]]=0;
            mp[nums[i][1]]++;
        }
        
        vector<int> w, l;
        for(auto i=mp.begin(); i!=mp.end(); i++) {
            if(i->second==0)
            w.push_back(i->first);
            if(i->second==1)
                l.push_back(i->first);
        }
        return {w, l};
    }
};