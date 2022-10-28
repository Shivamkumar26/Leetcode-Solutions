class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(), m=box[0].size();
        vector<vector<char>> res(m, vector<char>(n,'.'));
        
        for(int i=0; i<n; i++) {
            int w=m-1;
            for(int j=m-1; j>=0; j--) {
                if(box[i][j]=='.') continue;
                if(box[i][j]=='#') res[w--][n-1-i]='#';
                else {
                    res[j][n-i-1]='*';
                    w = j-1;
                }
            }
        }
       
        return res;
    }
};