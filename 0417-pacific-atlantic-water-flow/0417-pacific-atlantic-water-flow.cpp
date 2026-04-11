class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j) {
        int m = heights.size(), n = heights[0].size();
        ocean[i][j] = true;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x>=0 && y>=0 && x<m && y<n && !ocean[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(heights, ocean, x, y);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));
        
        // Pacific borders
        for (int i=0; i<m; i++) dfs(heights, pacific, i, 0);
        for (int j=0; j<n; j++) dfs(heights, pacific, 0, j);
        
        // Atlantic borders
        for (int i=0; i<m; i++) dfs(heights, atlantic, i, n-1);
        for (int j=0; j<n; j++) dfs(heights, atlantic, m-1, j);
        
        vector<vector<int>> res;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
