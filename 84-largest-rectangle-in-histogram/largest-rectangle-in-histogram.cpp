class Solution {
public:
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
};