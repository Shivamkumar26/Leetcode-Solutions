class Solution {
    vector<int> nextSmallRight(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, n);

        for(int i=n-1; i>=0; i--) {
            while(st.size() && nums[st.top()]>=nums[i]) {
                st.pop();
            }
            if(st.size()) res[i] = st.top();
            st.push(i);
        }

        return res;
    }

    vector<int> nextSmallLeft(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1);

        for(int i=0; i<n; i++) {
            while(st.size() && nums[st.top()]>nums[i]) {
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

        vector<int> lns = nextSmallLeft(nums);
        vector<int> rns = nextSmallRight(nums);


        for(int i=0; i<n; i++) {
            cout << lns[i] << " ";
        }
        cout << endl;
for(int i=0; i<n; i++) {
            cout << rns[i] << " ";
        }
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