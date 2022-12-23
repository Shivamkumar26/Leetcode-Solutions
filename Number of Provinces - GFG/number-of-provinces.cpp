//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int i, vector<int> adj[], vector<int>& vis) {
        vis[i] = 1;
        for(auto it: adj[i]) 
            if(vis[it] == 0) dfs(it, adj, vis);
    }
  public:
    int numProvinces(vector<vector<int>> adjm, int v) {
        //adj matrix is given we have to create list
        vector<int> adj[v];
        for(int i=0; i<v; i++)
            for(int j=0; j<v; j++)
                if(adjm[i][j]==1 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        
        vector<int> vis(v, 0);
        int ans = 0;
        for(int i = 0; i<v; i++)
            if(vis[i] == 0) {
                dfs(i, adj, vis);
                ans++;
            }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends