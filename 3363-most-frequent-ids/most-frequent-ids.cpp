class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, long long> mp;
        set<pair<long long, int>, greater<>> st;

        for(int i=0; i<n; i++) {
            mp[nums[i]] += freq[i];
            auto idx = st.find({mp[nums[i]]-freq[i], nums[i]});
            if(idx != st.end()) st.erase(idx);
            st.insert({mp[nums[i]], nums[i]});
            
            ans[i] = st.begin()->first;
        } 
        return ans;
    }
};