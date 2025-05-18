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

    long long sumofSubarrayMin(vector<int>& nums) {
        int n = nums.size();

        vector<int> nsl = nextSmallLeft(nums);
        vector<int> nsr = nextSmallRight(nums);

        for(int i=0; i<n; i++) {
            cout << nsl[i] << " ";
        }
        cout << endl;
        for(int i=0; i<n; i++) {
            cout << nsr[i] << " ";
        }
        cout << "\n\n";
        long long ans = 0;
        for(int i=0; i<n; i++) {
            long long rl = nsr[i]-i;
            long long ll = i - nsl[i];
            ans += (long long)nums[i]*rl*ll;
        }
        return ans;
    }

    vector<int> nextLargeRight(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, n);

        for(int i=n-1; i>=0; i--) {
            while(st.size() && nums[st.top()]<=nums[i]) {
                st.pop();
            }
            if(st.size()) res[i] = st.top();
            st.push(i);
        }

        return res;
    }

    vector<int> nextLargeLeft(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1);

        for(int i=0; i<n; i++) {
            while(st.size() && nums[st.top()]<nums[i]) {
                st.pop();
            }
            if(st.size()) res[i] = st.top();
            st.push(i);
        }

        return res;
    }


    long long sumofSubarrayMax(vector<int>& nums) {
        int n = nums.size();

        vector<int> nll = nextLargeLeft(nums);
        vector<int> nlr = nextLargeRight(nums);

        for(int i=0; i<n; i++) {
            cout << nll[i] << " ";
        }
        cout << endl;
        for(int i=0; i<n; i++) {
            cout << nlr[i] << " ";
        }
        cout << "\n\n";

        long long ans = 0;
        for(int i=0; i<n; i++) {
            long long rl = nlr[i]-i;
            long long ll = i - nll[i];
            ans += (long long)nums[i]*rl*ll;
        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumofSubarrayMax(nums) - sumofSubarrayMin(nums);
    }
};
/*

4 -2 -3 4 1 

4 -2 ->         6
4 -2 -3 ->      7 
4 -2 -3 4 ->    7
4 -2 -3 4 1 ->  7

-2 -3 ->        1
-2 -3 4 ->      7
-2 -3 4 1 ->    7

-3 4 ->         7
-3 4 1 ->       7
4 1 ->          5

*/