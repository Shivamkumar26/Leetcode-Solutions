class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for(int i=0; i<n; i++) {
            if(nums[i] > 0) st.push(nums[i]);
            else {
            while(st.size() && st.top()>0 && st.top() < abs(nums[i])) {
                st.pop();
            }
            if(st.size() && st.top()>0 && st.top() == abs(nums[i])) {
                st.pop();
            }
            else if(st.size() == 0 || st.top()<0) st.push(nums[i]);
            }
        }
        vector<int> res(st.size());
        n = st.size();
        for(int i=n-1; i>=0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};