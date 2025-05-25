class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size();

        int l = 1, r = INT_MAX, ans = INT_MAX;
        while(l <= r) {
            int mid = (r-l)/2 + l;
            int time = 0;
            for(int i=0; i<n; i++) {
                time += nums[i]/mid;
                if(nums[i] % mid) time++;

                if(time > h) break;
            }
            if(time <= h) {
                ans = min(ans, mid);
                r = mid-1;
            }
            else if(time > h) l = mid+1;

            cout << "l " << l << " r " << r << endl; 
        }
        return ans;
    }
};
/*

k : ?
h : 8

5

3 4

11

*/