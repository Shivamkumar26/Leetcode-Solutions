class Solution {
    vector<int> leftNearestSmallestElementIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(st.size() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(st.size()) res[i] = st.top();
            st.push(i);
        }

        return res;
    }

     vector<int> rightNearestSmallestElementIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, n);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(st.size() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if(st.size()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> lns = leftNearestSmallestElementIndex(nums);
        vector<int> rns = rightNearestSmallestElementIndex(nums);

        for(int i=0; i<n; i++) {
            long long lt = i - lns[i];
            long long rt = rns[i] - i;
            long long t = (lt*rt*nums[i])%mod;
            ans = (ans + t) % mod;
        }

        return ans;
    }
};
/*

left - next smallest
right - next smallest



*/