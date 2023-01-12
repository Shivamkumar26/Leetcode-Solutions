class Solution {
public:
    void countSameLabel(int node, vector<vector<int>>&graph,string &labels,vector<bool>&visited,vector<vector<int>>&freqList,vector<int>&result)
    {
        visited[node] = true;
        
        for(int i=0; i<graph[node].size(); i++) {
            if(!visited[graph[node][i]]) {
            countSameLabel(graph[node][i], graph, labels, visited, freqList, result);
                
                result[node]+= freqList[graph[node][i]][labels[node]-'a'];             
                for(int j=0;j<26;j++)
                    freqList[node][j]+= freqList[graph[node][i]][j];
            }
        }        
        freqList[node][labels[node]-'a']++;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n,false);
        vector<int> result(n,1);
        
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<vector<int>> freqList (n,vector<int>(26,0));
        countSameLabel (0, graph, labels, visited, freqList, result);
        
        return result;
    }
};