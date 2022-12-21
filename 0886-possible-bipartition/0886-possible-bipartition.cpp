class Solution {
public:
    vector<int> color; 
	bool dfs( vector<vector<int>>& graph, int col, int cur) {
		color[cur]=col;
		for(auto& x:graph[cur]) {
			if(color[x]==color[cur]) return false; // has same color with neighbor
			if(color[x]==0)
				if(!dfs(graph,-col,x)) return false;
		}
		return true;
	}
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		color.assign(N+1,0);
		vector<vector<int>> graph(N+1);
		for(auto& x:dislikes) {
			graph[x[0]].push_back(x[1]); 
			graph[x[1]].push_back(x[0]);
		}

		for(int i=1;i<=N;i++) {
			if(color[i]==0) {
				if(!dfs(graph,1,i)) return false;
			}
		}
		return true;
	}
};
    