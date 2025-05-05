class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) mp[nums[i]]++;

        priority_queue<pair<int, int>> pq;
        for(auto i = mp.begin(); i!=mp.end(); i++) {
            int ele = i->first;
            int freq = i->second;
            pq.push({freq, ele});
        }

        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};