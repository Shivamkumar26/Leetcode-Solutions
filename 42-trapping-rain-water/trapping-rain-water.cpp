class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax= 0 , rmax= 0, ans = 0, l = 0, r = n-1;
        while(l<=r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            ans += (min(lmax, rmax) - min(height[l], height[r]));
            if(height[l]<=height[r]) l++;
            else r--;
        }
        return ans;
    }
};
/*

lmax
rmax

- move left and right


*/