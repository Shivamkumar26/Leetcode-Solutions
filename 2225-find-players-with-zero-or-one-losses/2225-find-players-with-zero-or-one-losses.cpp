class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // >0 - w 
        // -1 = lost one m
        // -2 = lost more than one 
        int n = matches.size();
        map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            int w = matches[i][0];
            int l = matches[i][1];
            
            if(mp.find(w)==mp.end() || mp[w]>0) mp[w]++;
            if(mp.find(l)==mp.end() || mp[l]<0) mp[l]--;
            else mp[l] = -1;
        }
        
        vector<vector<int>> ans(2);
        for(auto i=mp.begin(); i!=mp.end(); i++) {
            if(i->second > 0) ans[0].push_back(i->first);
            else if(i->second == -1) ans[1].push_back(i->first);
        }
        return ans;
    }
};