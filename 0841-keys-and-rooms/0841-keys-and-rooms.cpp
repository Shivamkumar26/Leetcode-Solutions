class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& nums) {
        queue<int> q;
        int n = nums.size();
        vector<bool> vis(n, 0);
        
        q.push(0);
        while(q.size()) {
            int m = q.size();
            for(int i=0; i<m; i++) {
                int topIndex = q.front();
                q.pop();
                if(vis[topIndex]!=1) {
                    vis[topIndex] = 1;
                    vector<int> v = nums[topIndex];
                    for(int i=0; i<v.size(); i++) {
                        q.push(v[i]);
                    }
                }
            }
        }
        for(int i=0; i<vis.size(); i++) {
            if(vis[i]==0) return false;
        }
        return true;
    }
};