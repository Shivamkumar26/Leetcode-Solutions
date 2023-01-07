class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        int n = g.size(), ct = 0, t = 0, ans = 0;
        
        for(int i=0; i<n; i++) {
            ct += g[i] - c[i];
            t += g[i] - c[i];
            
            if(t < 0) t = 0, ans = i+1;
        }
        return ct < 0 ? -1 : ans;
    }
};

/*

tank = prev ans - cost + gas[i]

i=3; 4 8 7 6 5 

*/