class Solution {
    void addbit(vector<int>& bit, int num, bool add) {
        int i=0;
        while(num>0) {
            int r = num%2;
            int toAdd = add ? 1 : -1;
            bit[i] += r ? toAdd : 0;
            num /= 2;
            i++;
        }
    }
    bool greaterVal(vector<int>& bit, int k) {
        int num = 0;
        for(int i=0; i<32; i++) {
            if(bit[i]) num += pow(2, i);
        }
        return (num>=k);
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;;

        vector<int> bit(32, 0);
        int l = 0;
        for(int i=0; i<n; i++) {
            addbit(bit, nums[i], true); // add right ele bits in bit array
            while(greaterVal(bit, k) && l<=i) {
                ans = min(ans, i-l+1);
                addbit(bit, nums[l], false); // remove left ele bits
                l++;
            }
        }

        return ans==INT_MAX ? -1 : ans;
    }
};