class Solution {
    void dfs(int r, int c, vector<vector<int>>& image, int beforeColor, int afterColor) {
        int n = image.size(), m = image[0].size();
        image[r][c] = afterColor;
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++) {
            int cr = r + dr[i];    
            int cc = c + dc[i];    
            if(cr >=0 && cr < n && cc >=0 && cc < m && image[cr][cc]==beforeColor && image[cr][cc]!=afterColor) {
                dfs(cr, cc, image, beforeColor, afterColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int colorToChange = image[sr][sc];
        
        dfs(sr, sc, image, colorToChange, color);
        return image;
    }
};