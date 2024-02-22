class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n+1, 0);
        vector<int> v2(n+1, 0);
        int m = trust.size();
        for(int i = 0; i < m; i++) {
            v[trust[i][0]] = 1;
            v2[trust[i][1]]++;
        }
        int ele = -1;
        for(int i = 1; i <= n; i++) {
            if(v[i] == 0 && v2[i] == n-1) return i;
        }
        return -1;
    }
};