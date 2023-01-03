class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int m = strs.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(strs[j][i] >= strs[j-1][i]) continue;
                else { ans++; break; }
            }
        }
        return ans;
    }
};