class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        if(!graph.size()) return ans;
        int e = graph.size()-1;
        queue<vector<int>> q;
        q.push({0});
        
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                auto v = q.front();
                q.pop();
                if(v.back() == e) ans.push_back(v);
                     
                for(auto &it: graph[v.back()]) {
                    vector<int> copy = v;
                    // if(find(begin(v), end(v), it) != v.end())
                    //     continue;
                    copy.push_back(it);
                    q.push(copy);
                }
            }
        }
        return ans;
    }
};