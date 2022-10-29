class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        // from observation we will pick that plant whose growtime is more
        // 2nd example for just confusion dont see it.
        int n = plantTime.size();
        vector<vector<int>> ds(n);
        
        for(int i=0; i<n; i++) {
            ds[i] = {growTime[i], plantTime[i]};
        }
        sort(ds.rbegin(), ds.rend());
        
        /* 
        
        gt      pt
        {3,2,1} {4,1,3}
        time = 8
        mx = 7, 5+2,  9
          
        */
        
        int time = 0, mx = 0;
        for(int i=0; i<n; i++) {
            time += ds[i][1]; //planting time
            mx = max(mx, time + ds[i][0]);
        }
        return mx;
    }
};