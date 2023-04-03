class Solution {
public:
    int miceAndCheese(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        priority_queue<int> pq;
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += nums2[i];
            pq.push(-nums1[i]+nums2[i]);
            if(pq.size() > k) pq.pop();
        }
        while(pq.size()) {
            ans -= pq.top();
            pq.pop();
        }
        return ans;
    }
};
