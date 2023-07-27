class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int l = 1, h = 1e7;
        int ans = -1;
        while(l <= h) {
            int mid = l + (h-l)/2;
            double ch = 0.0;

            for(int i=0; i < n-1; i++) 
                ch += (dist[i]+mid-1)/ mid; // rounding off
            ch += (double)(dist[n-1])/(double)(mid);

            if(ch <= hour) ans = mid, h = mid-1;
            else l = mid + 1;
        }
        return ans;
    }
};