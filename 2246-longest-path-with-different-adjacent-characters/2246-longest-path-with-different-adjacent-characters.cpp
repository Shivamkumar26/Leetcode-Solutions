class Solution {
    int dfs(int index, vector<vector<int>>&tree, string &s, int &maxLength) {        
        int max1 = 0, max2 = 0, len;

        for(int i=0; i<tree[index].size(); i++) {
            len = dfs(tree[index][i],tree,s,maxLength);

            // if child and parent has diff char
            if(s[index]!=s[tree[index][i]]) {
                if(max1 < len) {
                    max2 = max1;
                    max1 = len;
                }
                else if(max2 < len) max2 = len;
            }
        }
        max1++;
        maxLength = max(max1 + max2, maxLength);
        return max1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n);        
        for(int i=1; i<n; i++) tree[parent[i]].push_back(i);
        
        int maxLength = 0;
        dfs(0, tree, s, maxLength);
        
        return maxLength;
    }

};