class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>> pq; //sum, idx
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k) pq.push({sum, {i, j}});
                else if(pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                }
                else break;
            }
        }

        while(pq.size()){
            ans.push_back({nums1[pq.top().second.first], nums2[pq.top().second.second]});
            pq.pop();
        }
        return ans;
    }
};