class Solution {
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(st.size() && nums[st.top()] >= nums[i]) {
                int t = st.top();
                st.pop();

                ans = max(ans, (i -1 - (st.size() ? st.top() : -1))*nums[t]);
            }
            st.push(i);
        }
        while(st.size()) {
            int t = st.top();
            st.pop();

            ans = max(ans, (n -1 - (st.size() ? st.top() : -1))*nums[t]);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        vector<int> res(m, 0);
        for(int i=0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == '0') res[j] = 0;
                else res[j] += (grid[i][j]-'0');
            }
            ans = max(ans, largestRectangleArea(res));
        }

        return ans;
    }
};