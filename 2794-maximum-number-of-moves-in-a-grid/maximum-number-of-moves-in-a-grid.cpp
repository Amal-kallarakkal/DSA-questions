class Solution {
public:
    int dx[3] = {-1, 0, 1};
    int nx, ny;

    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        int row = grid.size();
        int col = grid[0].size();
        if(dp[x][y]) return dp[x][y];

        for(int i = 0 ; i < 3 ; i ++) {
            nx = x + dx[i];
            ny = y + 1;
            if(nx < 0 || nx >= row || ny >= col) continue;
            if(grid[nx][ny] > grid[x][y]) {
                dp[x][y] = max(dp[x][y] , 1 + dfs(nx, ny, grid, dp));                
            }
        }
        
        return dp[x][y];
    }
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxi = 0;
        vector<vector<int>> dp(row, vector<int> (col, 0));

        for(int i = 0; i < row; i++) {
            dp[i][0] = dfs(i, 0, grid, dp);
            maxi = max(maxi , dp[i][0]);
        }
        
        return maxi;
    }
};