class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n, 0);
        suff[n-1] = nums[n-1];

        //  24 24 12 4
        // 24 12 8 6
        for(int i=n-2; i>=0; i--) {
            suff[i] = suff[i+1]*nums[i];
            cout << suff[i] << " ";
        }

        cout << endl;
        vector<int> res(n);
        int pre = 1;
        for(int i=0; i<n; i++) {
            if(i+1 < n) res[i] = pre*suff[i+1];
            else res[i] = pre;
            pre = pre*nums[i];
        }
        return res;
    }
};