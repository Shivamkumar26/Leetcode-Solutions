class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n-1, lm = 0, rm = 0, ans = 0;

        while (l < r) {
            int currWater = (r-l)*(min(h[l], h[r]));
            ans = max(ans, currWater);
            if(h[l]>h[r]) r--;
            else l++;
        }
        return ans;
    }
};