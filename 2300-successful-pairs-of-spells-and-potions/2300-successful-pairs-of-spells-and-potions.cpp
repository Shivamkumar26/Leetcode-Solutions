class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& po, long long success) {
        int n = sp.size(), m = po.size();
        sort(po.begin(), po.end());
        vector<int> ans(n);
        
        for(int i=0; i<n; i++) {
            long long prod = sp[i];
            int left = 0, right = m - 1, ind = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long s_p = po[mid] * prod;
                if (s_p >= success) {
                    ind = mid;
                    right = mid - 1;
                } else left = mid + 1;
            }
            if(ind == -1) ans[i] = 0;
            else ans[i] = m - ind;
        }
        return ans;
    }
};

/*

s*p >= success

*/