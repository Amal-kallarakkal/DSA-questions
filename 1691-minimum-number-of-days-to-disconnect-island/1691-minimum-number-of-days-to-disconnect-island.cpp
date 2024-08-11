class Solution {
public:
    // util array d, u, l ,r
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int ny, nx;
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &visited, int &row, int &col) {
        visited[r][c] = 1;
        for(int i = 0 ;i < 4; i++) {
            nx = r + dx[i];
            ny = c + dy[i];
            if(ny < 0 || nx < 0 || nx >= row || ny >= col) continue;
            if(grid[nx][ny] && !visited[nx][ny]) {
                dfs(nx, ny, grid, visited, row, col);
            }
        }
    }
    int countIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int cnt = 0;
        for(int i = 0 ; i < row; i++ ) {
            for(int j =0; j < col; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    cnt++;
                    dfs(i, j, grid, visited, row, col);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        
        int cnt = countIsland(grid);
        if(cnt > 1 || cnt == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        
        // check for one move
        for(int i = 0 ; i < row; i++) {            
            for(int j = 0 ; j < col; j++ ) {   
                
                if(grid[i][j]) {                    
                    grid[i][j] = 0;
                    cnt = countIsland(grid);
                    if(cnt > 1 || cnt == 0) return 1;
                    grid[i][j] = 1;                    
                    
                }
            }
        }

        return 2;

        
    }
};

/*
    [1,1,0,1,1]
    [1,1,0,1,1]
    [1,1,0,1,1]
    [1,1,1,1,1]

*/