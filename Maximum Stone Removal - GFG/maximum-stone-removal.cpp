//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void dfs(vector<vector<int>>& stone, vector<bool>& vis, int ind, int n) {
        vis[ind]=1;
        for(int i=0; i<n; i++) {
            if(!vis[i]) 
            if(stone[i][0]==stone[ind][0]  || stone[ind][1]==stone[i][1])
            dfs(stone, vis, i, n);
        }
    }
public:
    int maxRemove(vector<vector<int>>& stone, int n) {
        vector<bool> visited(n, false);
        int ans = n;
        for(int i = 0; i<n; i++) {
            if(!visited[i]) { 
                dfs(stone, visited, i, n);
                ans--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x; cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj,n) << "\n";
    }
}
// } Driver Code Ends